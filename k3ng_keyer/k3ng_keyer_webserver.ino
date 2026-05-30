// webserver related functions

void initialize_web_server(){
  #if defined(FEATURE_WEB_SERVER)

    server.begin();

    #ifdef DEBUG_WEB_SERVER 
      debug_serial_port->print(F("initialize_web_server: server is at "));
      debug_serial_port->println(NETWORK_LOCAL_IP);
    #endif

  #endif //FEATURE_WEB_SERVER
}


//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void service_web_server() {

  #ifdef DEBUG_WEB_SERVER_READS
  debug_serial_port->println(F("loop: entering service_web_server"));
  #endif

#if defined(ENALBLE_WIFI)
  if (!check_wifi_connected()) {
    return;
  }
#endif

  if ((web_control_tx_key_time > 0) && ((millis()-web_control_tx_key_time) > (WEB_SERVER_CONTROL_TX_KEY_TIME_LIMIT_SECS*1000))){
    tx_and_sidetone_key(0);
    web_control_tx_key_time = 0;
  }

  // Create a client connection
  NETWORK_CLIENT_CLS client = server.available();
  if (client) {

    valid_request = 0;
  #ifdef command_mode_active_led
    if (command_mode_active_led) {digitalWrite(command_mode_active_led,HIGH);}
  #endif
    while (client.connected()){
      if (client.available()){
        char c = client.read();

        //read char by char HTTP request
        if (web_server_incoming_string.length() < MAX_WEB_REQUEST){
          //store characters to string
          web_server_incoming_string += c;
          #if defined(DEBUG_WEB_SERVER_READS)
            debug_serial_port->print("service_web_server: read: ");
            debug_serial_port->print(c);
          #endif //DEBUG_WEB_SERVER_READS
        } else {
          // web_server_incoming_string = "";
        }

        //has HTTP request ended?
        if (c == '\n'){

          #if defined(DEBUG_WEB_SERVER_READS)
            debug_serial_port->println(web_server_incoming_string); //print to serial monitor for debuging
          #endif //DEBUG_WEB_SERVER_READS

          if (web_server_incoming_string.startsWith("GET / ")){
            valid_request = 1;
            web_print_page_main_menu(client);
          }

          if (web_server_incoming_string.startsWith("GET /About")){
            valid_request = 1;
            web_print_page_about(client);
          }

          if (web_server_incoming_string.startsWith("GET /KeyerSettings")){
            valid_request = 1;
            // are there form results being posted?
            if (web_server_incoming_string.indexOf("?") > 0){
              web_print_page_keyer_settings_process(client);
            } else {
              web_print_page_keyer_settings(client);
            }
          }

          if (web_server_incoming_string.startsWith("GET /NetworkSettings")){
            valid_request = 1;
            // are there form results being posted?
#if defined(FEATURE_ETHERNET)
            if (web_server_incoming_string.indexOf("?ip0=") > 0){
#elif defined(FEATURE_WIFI)
            if (web_server_incoming_string.indexOf("wifi_ssid=") > 0){      
#else
            if (false) {
#endif
              web_print_page_network_settings_process(client);
            } else {
              web_print_page_network_settings(client);
            }
          }

          #if defined(FEATURE_INTERNET_LINK)
            if (web_server_incoming_string.startsWith("GET /LinkSettings")){
              valid_request = 1;
              // are there form results being posted?
              if (web_server_incoming_string.indexOf("?ip") > 0){
                web_print_page_link_settings_process(client);
              } else {
                web_print_page_link_settings(client);
              }
            }
          #endif //FEATURE_INTERNET_LINK
          if (web_server_incoming_string.startsWith("GET /ctrl")){
            valid_request = 1;
            web_print_page_control(client);
          }

          #if defined(FEATURE_MEMORIES)
            if (web_server_incoming_string.startsWith("GET /mem")){
              valid_request = 1;
              // are there form results being posted?
              // if (web_server_incoming_string.indexOf("?") > 0){
              //   web_print_page_memories_process(client);
              // } else {
                web_print_page_memories(client);
              // }
            }
          #endif //FEATURE_MEMORIES


          if (!valid_request){
            web_print_page_404(client);
          }

          delay(1);
          client.stop();
          web_server_incoming_string = "";
         }
       }
    }
#ifdef command_mode_active_led
    if (command_mode_active_led) {digitalWrite(command_mode_active_led,LOW);}
#endif
  }
}
#endif //FEATURE_WEB_SERVER


//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_print_200OK(NETWORK_CLIENT_CLS client){

  web_client_print(client,F("HTTP/1.1 200 OK\nContent-Type: text/html\n\n"));

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_header(NETWORK_CLIENT_CLS client){

  web_print_200OK(client);
  web_client_println(client,F("<HTML><HEAD><meta name='apple-mobile-web-app-capable' content='yes' /><meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />"));

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_style_sheet(NETWORK_CLIENT_CLS client){

  web_client_print(client,F("<style>body{margin:60px 0px; padding:0px;text-align:center;font-family:\"Trebuchet MS\", Arial, Helvetica, sans-serif;}h1{text-align: center;font-family:Arial, \"Trebuchet MS\", Helvetica,"));
  web_client_print(client,F("sans-serif;}h2{text-align: center;font-family:\"Trebuchet MS\", Arial, Helvetica, sans-serif;}"));

  // internal hyperlinks
  web_client_print(client,F("a.internal{text-decoration:none;width:75px;height:50px;border-color:black;border-top:2px solid;border-bottom:2px solid;border-right:2px solid;border-left:2px solid;border-radius:10px 10px 10px;"));
  web_client_print(client,F("-o-border-radius:10px 10px 10px;-webkit-border-radius:10px 10px 10px;font-family:\"Trebuchet MS\",Arial, Helvetica, sans-serif;"));
  web_client_print(client,F("-moz-border-radius:10px 10px 10px;background-color:#293F5E;padding:8px;text-align:center;}"));
  web_client_print(client,F("a.internal:link {color:white;} a.internal:visited {color:white;}"));
  web_client_print(client,F(" a.internal:hover {color:white;} a.internal:active {color:white;}"));

  // control screen buttons
  web_client_print(client,F("a.ctrl{text-decoration:none;width:75px;height:50px;border-color:black;border-top:2px solid;border-bottom:2px solid;border-right:2px solid;border-left:2px solid;border-radius:10px 10px 10px;"));
  web_client_print(client,F("-o-border-radius:10px 10px 10px;-webkit-border-radius:10px 10px 10px;font-family:\"Trebuchet MS\",Arial, Helvetica, sans-serif;"));
  web_client_print(client,F("-moz-border-radius:10px 10px 10px;background-color:#293F5E;padding:15px;text-align:center;}"));
  web_client_print(client,F("a.ctrl:link {color:white;} a.ctrl:visited {color:white;}"));
  web_client_print(client,F(" a.ctrl:hover {color:white;} a.ctrl:active {color:white;}"));

  // external hyperlinks
  web_client_print(client,F("a.external{"));
  web_client_print(client,F("font-family:\"Trebuchet MS\",Arial, Helvetica, sans-serif;"));
  web_client_print(client,F("text-align:center;}"));
  web_client_print(client,F("a.external:link {color:blue;} a.external:visited {color:purple;}"));
  web_client_println(client,F(" a.external:hover {color:red;} a.external:active {color:green;}"));

  // ip address text blocks
  web_client_println(client,F(".addr {width: 3em; text-align:center }"));

  // ip port text blocks
  web_client_println(client,F(".ipprt {width: 45px; text-align:center }"));

 // text inputsblocks
  web_client_println(client,F("input.txt {width: 150px; text-align:left }"));
  web_client_println(client,F("span.txt {width: 100px; text-align:right }"));


  web_client_println(client,F(".container {display: flex;}"));

 /*for demo purposes only */
  // web_client_println(client,F(".column {flex: 1; background: #f2f2f2; border: 1px solid #e6e6e6; box-sizing: border-box;}"));
  // web_client_println(client,F(".column-1 {order: 1;} .column-2 {order: 2;} .column-3 {order: 3;} .column-4 {order: 4;} .column-5 {order: 5;}"));

  web_client_println(client,F("</style>"));

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_home_link(NETWORK_CLIENT_CLS client){

  web_client_println(client,F("<br><a href=\"\x2F\" class=\"internal\">Home</a><br />"));

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_footer(NETWORK_CLIENT_CLS client){


  web_client_println(client,F("<br></BODY></HTML>"));


}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_title(NETWORK_CLIENT_CLS client){


  web_client_println(client,F("<TITLE>K3NG CW Keyer</TITLE></HEAD><BODY>"));

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_network_settings(NETWORK_CLIENT_CLS client){

  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>Network Settings</H1><hr><br>"));

#if defined(FEATURE_ETHERNET)
  // input form
  web_client_print(client,F("<br><br><form>IP: <input type=\"text\" name=\"ip0\" class=\"addr\" value=\""));
  web_client_print(client,configuration.ip[0]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"ip1\" class=\"addr\" value=\""));
  web_client_print(client,configuration.ip[1]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"ip2\" class=\"addr\" value=\""));
  web_client_print(client,configuration.ip[2]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"ip3\" class=\"addr\" value=\""));
  web_client_print(client,configuration.ip[3]);
  web_client_println(client,"\">");


  web_client_print(client,F("<br><br>Gateway: <input type=\"text\" name=\"gw0\" class=\"addr\" value=\""));
  web_client_print(client,configuration.gateway[0]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"gw1\" class=\"addr\" value=\""));
  web_client_print(client,configuration.gateway[1]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"gw2\" class=\"addr\" value=\""));
  web_client_print(client,configuration.gateway[2]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"gw3\" class=\"addr\" value=\""));
  web_client_print(client,configuration.gateway[3]);
  web_client_println(client,"\">");

  web_client_print(client,F("<br><br>Subnet Mask: <input type=\"text\" name=\"sn0\" class=\"addr\" value=\""));
  web_client_print(client,configuration.subnet[0]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"sn1\" class=\"addr\" value=\""));
  web_client_print(client,configuration.subnet[1]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"sn2\" class=\"addr\" value=\""));
  web_client_print(client,configuration.subnet[2]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"sn3\" class=\"addr\" value=\""));
  web_client_print(client,configuration.subnet[3]);
  web_client_println(client,"\"><br><br><input type=\"submit\" value=\"Save\"></form>");
#elif defined(FEATURE_WIFI)
  //hier wifi html
  web_client_print(client,F("<br><br><form><span class=\"txt\">WiFi SSID: </span><input type=\"text\" class=\"txt\" name=\"wifi_ssid\" value=\""));
  web_client_print(client,configuration.wifi_ssid);
  web_client_print(client,F("\">"));
  web_client_print(client,F("<br><br><span class=\"txt\">WiFi password: </span><input type=\"password\" class=\"txt\" name=\"wifi_pwd\" value=\""));
  web_client_print(client,configuration.wifi_password);
  web_client_println(client,"\"><br><br><input type=\"submit\" value=\"Save\"></form>");
#else
  web_client_print(client,"No ethernet possible here.");
#endif

  web_print_home_link(client);

  web_print_footer(client);

}


#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER) && defined(FEATURE_INTERNET_LINK)

void web_print_page_link_settings(NETWORK_CLIENT_CLS client){

  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>Link Settings</H1><hr><br><H2>Link Send Settings</H2><form>"));


  // input form
  for (int x = 0;x < FEATURE_INTERNET_LINK_MAX_LINKS;x++){
    web_client_print(client,"<br><br>Link ");
    web_client_print(client,x+1);
    web_client_print(client,": IP: <input type=\"text\" name=\"ip");
    web_client_print(client,x);
    web_client_print(client,"0\" class=\"addr\" value=\"");
    web_client_print(client,configuration.link_send_ip[0][x]);
    web_client_print(client,"\"");
    web_client_print(client,">.<input type=\"text\" name=\"ip");
    web_client_print(client,x);
    web_client_print(client,"1\" class=\"addr\" value=\"");
    web_client_print(client,configuration.link_send_ip[1][x]);
    web_client_print(client,"\"");
    web_client_print(client,">.<input type=\"text\" name=\"ip");
    web_client_print(client,x);
    web_client_print(client,"2\" class=\"addr\" value=\"");
    web_client_print(client,configuration.link_send_ip[2][x]);
    web_client_print(client,"\"");
    web_client_print(client,">.<input type=\"text\" name=\"ip");
    web_client_print(client,x);
    web_client_print(client,"3\" class=\"addr\" value=\"");
    web_client_print(client,configuration.link_send_ip[3][x]);
    web_client_println(client,"\">");

    web_client_print(client," UDP Port: <input type=\"text\" name=\"sp");
    web_client_print(client,x);
    web_client_print(client,"\" class=\"ipprt\" value=\"");
    web_client_print(client,configuration.link_send_udp_port[x]);
    web_client_print(client,"\">  ");

    // link active/inactive radio buttons
    web_client_print(client,"<input type=\"radio\" name=\"act");
    web_client_print(client,x);
    web_client_print(client,"\" value=\"1\" ");
    if (configuration.link_send_enabled[x]) {web_client_print(client,"checked");}
    web_client_print(client,">Enabled <input type=\"radio\" name=\"act");
    web_client_print(client,x);
    web_client_print(client,"\" value=\"0\" ");
    if (!(configuration.link_send_enabled[x])) {web_client_print(client,"checked");}
    web_client_print(client,">Disabled<br>");

  }

  web_client_print(client,F("<br><br><H2>Link Receive Settings</H2><br><br>UDP Receive Port: <input type=\"text\" name=\"ud\" class=\"ipprt\" value=\""));
  web_client_print(client,configuration.link_receive_udp_port);
  web_client_println(client,"\">");

  web_client_print(client,"<input type=\"radio\" name=\"lr");
  web_client_print(client,"\" value=\"1\" ");
  if (configuration.link_receive_enabled) {web_client_print(client,"checked");}
  web_client_print(client,">Enabled <input type=\"radio\" name=\"lr");
  web_client_print(client,"\" value=\"0\" ");
  if (!(configuration.link_receive_enabled)) {web_client_print(client,"checked");}
  web_client_print(client,">Disabled<br>");

  web_client_println(client,"<br><br><input type=\"submit\" value=\"Save\"></form>");

  web_print_home_link(client);

  web_print_footer(client);

}


#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)

void web_print_page_404(NETWORK_CLIENT_CLS client){

  web_client_println(client,F("HTTP/1.1 404 NOT FOUND"));
  web_client_println(client,F("Content-Type: text/html\n"));
  web_client_println(client,F("<HTML><HEAD></HEAD><BODY>Sorry, dude.  Page not found."));
  web_print_home_link(client);
  web_print_footer(client);

}

#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)

void web_print_page_about(NETWORK_CLIENT_CLS client){

  web_print_header(client);

  web_client_println(client,F("<meta http-equiv=\"refresh\" content=\"5\"/>"));

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>About</H1><hr><br>"));
  web_client_println(client,CODE_VERSION);
  web_client_println(client,"<br>");

  #if !defined(HARDWARE_GENERIC_STM32F103C) && !defined(ARDUINO_RASPBERRY_PI_PICO_W) && !defined(ARDUINO_RASPBERRY_PI_PICO)
    void* HP = malloc(4);
    if (HP){
      free (HP);
    }
    #if defined(ESP32)
    unsigned long free = (ESP.getFreeHeap() - (unsigned long)HP);
    #else
    unsigned long free = (unsigned long)SP - (unsigned long)HP;
    #endif

    // web_client_print(client,"Heap = 0x");
    // web_client_println(client,(unsigned long)HP,HEX);
    // web_client_println(client,"<br />");
    // web_client_print(client,"Stack = 0x");
    // web_client_println(client,(unsigned long)SP,HEX);
    // web_client_println(client,"<br />");

    web_client_print(client,free);
    web_client_println(client,F(" bytes free<br><br>"));
  #endif




  unsigned long seconds = (millis() / 1000L) + ((pow(2,32)/ 1000L) *  millis_rollover);


  int days = seconds / 86400L;
  seconds = seconds - (long(days) * 86400L);

  int hours = seconds / 3600L;
  seconds = seconds - (long(hours) * 3600L);

  int minutes = seconds / 60L;
  seconds = seconds - (minutes * 60);

  web_client_print(client,days);
  web_client_print(client,":");
  if (hours < 10) {web_client_print(client,"0");}
  web_client_print(client,hours);
  web_client_print(client,":");
  if (minutes < 10) {web_client_print(client,"0");}
  web_client_print(client,minutes);
  web_client_print(client,":");
  if (seconds < 10) {web_client_print(client,"0");}
  web_client_print(client,seconds);
  web_client_println(client,F(" dd:hh:mm:ss uptime<br>"));

  web_client_println(client,F("<br><br><br>Anthony Good, K3NG<br>anthony.good@gmail.com<br><a href=\"http://blog.radioartisan.com/\"\" class=\"external\">Radio Artisan</a><br><br>"));

  web_print_home_link(client);

  web_print_footer(client);
}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
int web_hex_to_int(char c) {
  if ((c >= '0') && (c <= '9')) return c - '0';
  if ((c >= 'a') && (c <= 'f')) return c - 'a' + 10;
  if ((c >= 'A') && (c <= 'F')) return c - 'A' + 10;
  return -1;
}

String web_url_decode(String input) {
  String output = "";

  for (unsigned int i = 0; i < input.length(); i++) {
    char c = input.charAt(i);

    if (c == '+') {
      output += ' ';
    } else if ((c == '%') && ((i + 2) < input.length())) {
      int hi = web_hex_to_int(input.charAt(i + 1));
      int lo = web_hex_to_int(input.charAt(i + 2));

      if ((hi >= 0) && (lo >= 0)) {
        output += (char)((hi << 4) | lo);
        i += 2;
      } else {
        output += c;
      }
    } else {
      output += c;
    }
  }
  return output;
}

void parse_get(String str){

  String workstring = "";
  String parameter = "";
  String value = "";

  for(int x = 0;x < MAX_PARSE_RESULTS;x++){
    parse_get_results[x].parameter = "";
    parse_get_results[x].value_string = "";
    parse_get_results[x].value_long = 0;
  }
  parse_get_results_index = 0;

  #if defined(DEBUG_WEB_PARSE_GET)
    debug_serial_port->print("parse_get: raw workstring: ");
    Serial.println(str);
  #endif

  workstring = str.substring(str.indexOf("?")+1);

  #if defined(DEBUG_WEB_PARSE_GET)
    debug_serial_port->print("parse_get: workstring: ");
    Serial.println(workstring);
  #endif

  while(workstring.indexOf("=") > 0){
    parameter = workstring.substring(0,workstring.indexOf("="));
    if(workstring.indexOf("&") > 0){
      value = workstring.substring(workstring.indexOf("=")+1,workstring.indexOf("&"));
      workstring = workstring.substring(workstring.indexOf("&")+1);
    } else {
      value = workstring.substring(workstring.indexOf("=")+1,workstring.indexOf(" "));
      // value = workstring.substring(workstring.indexOf("=")+1);
      workstring = "";
    }
    parameter = web_url_decode(parameter);
    value = web_url_decode(value);

    #if defined(DEBUG_WEB_PARSE_GET)
      debug_serial_port->print("parse_get: parameter: ");
      debug_serial_port->print(parameter);
      debug_serial_port->print(" value: ");
      debug_serial_port->println(value);
    #endif //DEBUG_WEB_PARSE_GET

    if (parse_get_results_index < MAX_PARSE_RESULTS){
      parse_get_results[parse_get_results_index].parameter = parameter;
      parse_get_results[parse_get_results_index].value_string = value;
      parse_get_results[parse_get_results_index].value_long = value.toInt();

      // Serial.print(parse_get_results_index);
      // Serial.print(":");
      // Serial.print(parse_get_results[parse_get_results_index].parameter);
      // Serial.print(":");
      // Serial.print(parse_get_results[parse_get_results_index].value_string);
      // Serial.print(":");
      // Serial.print(parse_get_results[parse_get_results_index].value_long);
      // Serial.println("$");

      parse_get_results_index++;
    }
  }


}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_main_menu(NETWORK_CLIENT_CLS client){


  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>K3NG CW Keyer</H1><hr><br><br><a href=\"ctrl\"\" class=\"internal\">Control</a><br><br>"));
  #if defined(FEATURE_MEMORIES)
    web_client_println(client,F("<a href=\"mem\"\" class=\"internal\">Memories</a><br><br>"));
  #endif //FEATURE_MEMORIES
  web_client_println(client,F("<a href=\"KeyerSettings\"\" class=\"internal\">Keyer Settings</a><br><br>"));
  #if defined(FEATURE_INTERNET_LINK)
    web_client_println(client,F("<a href=\"LinkSettings\"\" class=\"internal\">Link Settings</a><br><br>"));
  #endif //FEATURE_INTERNET_LINK
  web_client_println(client,F("<a href=\"NetworkSettings\"\" class=\"internal\">Network Settings</a><br><br><a href=\"About\"\" class=\"internal\">About</a><br>"));

  web_print_footer(client);

}

#endif //FEATURE_WEB_SERVER


//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_control_radio(NETWORK_CLIENT_CLS client,const char *name,int value,uint8_t checked,const char *caption){

  web_client_print(client,F("<label><input type=\"radio\" name=\""));
  web_client_print(client,name);
  web_client_print(client,F("\" value=\""));
  web_client_print(client,value);
  web_client_print(client,"\"");
  if (checked) {web_client_print(client,F(" checked"));}
  web_client_print(client,">");
  web_client_print(client,caption);
  web_client_print(client,F("</label>"));

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_control_checkbox(NETWORK_CLIENT_CLS client,const char *name,uint8_t checked,const char *caption){

    web_client_print(client,F("<label><input type=\"checkbox\" id=\"cbox"));
    web_client_print(client,name);
    web_client_print(client,F("\" value=\""));
    web_client_print(client,name);
    web_client_print(client,F("\""));
    if (checked) {web_client_print(client,F(" checked"));}
    web_client_print(client,F(">"));
    web_client_print(client,caption);
    web_client_print(client,F("</label>"));

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_control_textbox(NETWORK_CLIENT_CLS client,const char *name,const char *textbox_class,int textbox_value,const char *front_caption,const char *back_caption){

  web_client_print(client,F("<label>"));
  web_client_print(client,front_caption);
  web_client_print(client,F("<input type=\"text\" name=\""));
  web_client_print(client,name);
  web_client_print(client,F("\" class=\""));
  web_client_print(client,textbox_class);
  web_client_print(client,F("\" value=\""));
  web_client_print(client,textbox_value);
  web_client_print(client,F("\">"));
  web_client_print(client,back_caption);
  web_client_print(client,F("</label>"));

}

//-------------------------------------------------------------------------------------------------------

void web_print_control_floatbox(NETWORK_CLIENT_CLS client,const char *name,const char *textbox_class,float textbox_value,const char *front_caption,const char *back_caption){

  web_client_print(client,F("<label>"));
  web_client_print(client,front_caption);
  web_client_print(client,F("<input type=\"text\" name=\""));
  web_client_print(client,name);
  web_client_print(client,F("\" class=\""));
  web_client_print(client,textbox_class);
  web_client_print(client,F("\" value=\""));
  web_client_print(client,textbox_value);
  web_client_print(client,F("\">"));
  web_client_print(client,back_caption);
  web_client_print(client,F("</label>"));

}
#endif //FEATURE_WEB_SERVER


//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_keyer_settings(NETWORK_CLIENT_CLS client){

  uint8_t pin_read = 0;

  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>Keyer Settings</H1><hr><br><form>"));

  web_print_control_radio(client,"md",IAMBIC_A,(configuration.keyer_mode == IAMBIC_A)?1:0,"Iambic A ");
  web_print_control_radio(client,"md",IAMBIC_B,(configuration.keyer_mode == IAMBIC_B)?1:0,"Iambic B ");
  web_print_control_radio(client,"md",BUG,(configuration.keyer_mode == BUG)?1:0,"Bug ");
  web_print_control_radio(client,"md",STRAIGHT,(configuration.keyer_mode == STRAIGHT)?1:0,"Straight Key");
  #ifndef OPTION_NO_ULTIMATIC
  web_print_control_radio(client,"md",ULTIMATIC,(configuration.keyer_mode == ULTIMATIC)?1:0,"Ultimatic");
  #endif
  web_print_control_radio(client,"md",SINGLE_PADDLE,(configuration.keyer_mode == SINGLE_PADDLE)?1:0,"Single Paddle");
  web_client_println(client,"<br>");


  #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
    web_print_control_checkbox(client,"cs",(configuration.cmos_super_keyer_iambic_b_timing_on)?1:0," CMOS Superkeyer Iambic B Timing ");
    web_print_control_textbox(client,"cp","addr",configuration.cmos_super_keyer_iambic_b_timing_percent,"","%");
    web_client_println(client,"<br>");
  #endif

  //web_print_control_checkbox(client,"di",(!configuration.dit_buffer_off)?1:0," Dit Buffer ");  // couldn't get checkboxes working correctly 2016-12-11

  web_client_print(client,"Dit Buffer");
  web_print_control_radio(client,"di",0,(configuration.dit_buffer_off)?0:1,"On ");
  web_print_control_radio(client,"di",1,(configuration.dit_buffer_off)?1:0,"Off   ");
  web_client_println(client,"<br>");

  // web_print_control_checkbox(client,"da",(!configuration.dah_buffer_off)?1:0," Dah Buffer<br>");

  web_client_print(client,"Dah Buffer");
  web_print_control_radio(client,"da",0,(configuration.dah_buffer_off)?0:1,"On ");
  web_print_control_radio(client,"da",1,(configuration.dah_buffer_off)?1:0,"Off");
  web_client_println(client,"<br>");

  web_print_control_radio(client,"sm",SPEED_NORMAL,(speed_mode == SPEED_NORMAL)?1:0,"Normal Speed Mode ");

  web_print_control_textbox(client,"wp","addr",(int)configuration.wpm,""," WPM ");

  #if defined(FEATURE_FARNSWORTH)
    web_print_control_textbox(client,"fw","addr",(int)configuration.wpm_farnsworth,""," Farnsworth WPM");
  #endif //FEATURE_FARNSWORTH

  web_client_println(client,"<br>");

  web_print_control_radio(client,"sm",SPEED_QRSS,(speed_mode == SPEED_QRSS)?1:0,"QRSS Mode   Dit Length ");
  web_client_print(client,F("<label><input type=\"text\" name=\"qd\" class=\"addr\" value=\""));
  web_client_println(client,qrss_dit_length);
  web_client_print(client,F("\"> s</label>"));
  web_client_println(client,F("<br>"));

  web_client_print(client,F("Sidetone: "));
  web_print_control_radio(client,"st",SIDETONE_ON,(configuration.sidetone_mode == SIDETONE_ON)?1:0,"On ");
  web_print_control_radio(client,"st",SIDETONE_OFF,(configuration.sidetone_mode == SIDETONE_OFF)?1:0,"Off ");
  web_print_control_radio(client,"st",SIDETONE_PADDLE_ONLY,(configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)?1:0,"Paddle Only ");
  web_print_control_textbox(client,"hz","addr",(int)configuration.hz_sidetone,""," hz");
  web_client_println(client,F("<br>"));

  web_print_control_floatbox(client,"dd","addr",float(configuration.dah_to_dit_ratio/100.0),""," Dah/Dit Ratio");
  web_client_println(client,F("<br>"));

  web_print_control_textbox(client,"wt","addr",(int)configuration.weighting,"Weighting ","");
  web_client_println(client,F("<br>"));

  #ifdef FEATURE_COMMAND_LINE_INTERFACE
    web_print_control_textbox(client,"sn","addr",(int)serial_number,"Serial # ","");
    web_client_println(client,F("<br>"));;
  #endif

  #if defined(FEATURE_POTENTIOMETER)
    //web_print_control_textbox(client,"po","addr",(int)pot_value_wpm(),"Potentiometer "," WPM ");
    //web_print_control_checkbox(client,"pa",(configuration.pot_activated)?1:0," Active");
    web_client_print(client,"Potentiometer ");
    web_print_control_radio(client,"pa",1,(configuration.pot_activated)?1:0,"Active ");
    web_print_control_radio(client,"pa",0,(configuration.pot_activated)?0:1,"Inactive");
    web_client_println(client,F("<br>"));
  #endif

  #if defined(FEATURE_AUTOSPACE)
    //web_print_control_checkbox(client,"as",(configuration.autospace_active)?1:0," Autospace<br>");
    web_client_print(client,"Autospace");
    web_print_control_radio(client,"as",1,(configuration.autospace_active)?1:0,"On ");
    web_print_control_radio(client,"as",0,(configuration.autospace_active)?0:1,"Off");
    web_client_println(client,"<br>");
  #endif //FEATURE_AUTOSPACE

  web_print_control_textbox(client,"ws","addr",(int)configuration.length_wordspace,"Wordspace ","");
  web_client_println(client,F("<br>"));

  web_print_control_textbox(client,"tx","addr",(int)configuration.current_tx,"TX ","");
  web_client_println(client,F("<br>"));

  #if defined(FEATURE_QLF)
    //web_print_control_checkbox(client,"ql",(qlf_active)?1:0," QLF<br>");

    web_client_print(client,"QLF");
    web_print_control_radio(client,"ql",1,(qlf_active)?1:0,"On ");
    web_print_control_radio(client,"ql",0,(qlf_active)?0:1,"Off");
    web_client_println(client,"<br>");

  #endif //FEATURE_QLF

  web_client_println(client,F("<br><br><input type=\"submit\" value=\"Save\"></form>"));

  web_print_home_link(client);

  web_print_footer(client);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)

void web_print_page_keyer_settings_process(NETWORK_CLIENT_CLS client){


  uint8_t invalid_data = 0;

  unsigned int ud = 0;

  uint8_t temp_keyer_mode = 0;
  uint8_t temp_dit_buffer_off = 0;
  uint8_t temp_dah_buffer_off = 0;
  uint8_t temp_speed_mode = 0;
  unsigned int temp_wpm = 0;
  unsigned int temp_qrss_dit_length = 0;
  uint8_t temp_sidetone_mode = 0;
  unsigned int temp_sidetone_hz = 0;
  String temp_string_dit_dah_ratio;
  uint8_t temp_weight = 0;
  unsigned int temp_serial = 0;
  uint8_t temp_wordspace = 0;
  uint8_t temp_tx = 0;

  #if defined(FEATURE_QLF)
    uint8_t temp_qlf = 0;
  #endif //FEATURE_QLF

  #if defined(FEATURE_POTENTIOMETER)
    uint8_t temp_pot_activated = 0;
  #endif //FEATURE_POTENTIOMETER

  #if defined(FEATURE_AUTOSPACE)
    uint8_t temp_autospace_active = 0;
  #endif //FEATURE_AUTOSPACE

  #if defined(FEATURE_FARNSWORTH)
    unsigned int temp_farnsworth = 0;
  #endif //FEATURE_FARNSWORTH

  parse_get(web_server_incoming_string);

  if (parse_get_results_index){



    for (int x = 0; x < parse_get_results_index; x++){
      if (parse_get_results[x].parameter == "md"){temp_keyer_mode = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "di"){temp_dit_buffer_off = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "da"){temp_dah_buffer_off = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sm"){temp_speed_mode = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "wp"){temp_wpm = parse_get_results[x].value_long;}
      #if defined(FEATURE_FARNSWORTH)
        if (parse_get_results[x].parameter == "fw"){temp_farnsworth = parse_get_results[x].value_long;}
      #endif //FEATURE_FARNSWORTH
      if (parse_get_results[x].parameter == "qd"){temp_qrss_dit_length = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "st"){temp_sidetone_mode = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "hz"){temp_sidetone_hz = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "dd"){temp_string_dit_dah_ratio = parse_get_results[x].value_string;}
      if (parse_get_results[x].parameter == "wt"){temp_weight = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sn"){temp_serial = parse_get_results[x].value_long;}
      // po - nothing to do for potentiometer value
      #if defined(FEATURE_POTENTIOMETER)
        if (parse_get_results[x].parameter == "pa"){temp_pot_activated = parse_get_results[x].value_long;}
      #endif //FEATURE_POTENTIOMETER
      #if defined(FEATURE_AUTOSPACE)
        if (parse_get_results[x].parameter == "as"){temp_autospace_active = parse_get_results[x].value_long;}
      #endif //FEATURE_AUTOSPACE
      if (parse_get_results[x].parameter == "ws"){temp_wordspace = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "tx"){temp_tx = parse_get_results[x].value_long;}
      #if defined(FEATURE_QLF)
        if (parse_get_results[x].parameter == "ql"){temp_qlf = parse_get_results[x].value_long;}
      #endif //FEATURE_QLF


    }


    // data validation


    // TODO !  data validation


    if (invalid_data){

      web_print_header(client);
  #if defined(FEATURE_ETHERNET)
      web_print_meta_refresh(client,configuration.ip[0],configuration.ip[1],configuration.ip[2],configuration.ip[3],2);
  #endif
      web_client_println(client,F("\/KeyerSettings'\" />"));
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Bad data!<br>"));
      web_print_home_link(client);
      web_print_footer(client);

    } else {

    // assign to variables

      configuration.keyer_mode = temp_keyer_mode;
      configuration.dit_buffer_off = temp_dit_buffer_off;
      configuration.dah_buffer_off = temp_dah_buffer_off;
      speed_mode = temp_speed_mode;
      configuration.wpm = temp_wpm;
      qrss_dit_length = temp_qrss_dit_length;
      configuration.sidetone_mode = temp_sidetone_mode;
      configuration.hz_sidetone = temp_sidetone_hz;
      configuration.dah_to_dit_ratio =  int(temp_string_dit_dah_ratio.toFloat()*100.0);
      if (configuration.dah_to_dit_ratio < 150 || configuration.dah_to_dit_ratio > 700) {
        configuration.dah_to_dit_ratio = 300;
      }
      configuration.weighting = temp_weight;
      #if defined(FEATURE_COMMAND_MODE)
        serial_number = temp_serial;
      #endif
      configuration.length_wordspace = temp_wordspace;
      configuration.current_tx = temp_tx;
      #if defined(FEATURE_QLF)
        qlf_active = temp_qlf;
      #endif //FEATURE_QLF
      #if defined(FEATURE_POTENTIOMETER)
        configuration.pot_activated = temp_pot_activated;
      #endif //FEATURE_POTENTIOMETER
      #if defined(FEATURE_AUTOSPACE)
        configuration.autospace_active = temp_autospace_active;
      #endif //FEATURE_AUTOSPACE
      #if defined(FEATURE_FARNSWORTH)
        configuration.wpm_farnsworth = temp_farnsworth;
      #endif //FEATURE_FARNSWORTH

      web_print_header(client);
#if defined(FEATURE_ETHERNET)
      web_print_meta_refresh(client,configuration.ip[0],configuration.ip[1],configuration.ip[2],configuration.ip[3],2);
#endif
      web_client_println(client,F("\/KeyerSettings'\" />"));
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Configuration saved<br><br>"));
      web_print_home_link(client);
      web_print_footer(client);
      config_dirty = 1;
    }
  }
}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER) && defined(FEATURE_MEMORIES)

void web_print_page_memories(NETWORK_CLIENT_CLS client){



  int memory_number_to_send = 0;
  int last_memory_location;

  #if defined(OPTION_PROSIGN_SUPPORT)
    byte eeprom_temp = 0;
    static char * prosign_temp = 0;
  #endif




  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>Memories</H1><hr><br>"));

  web_client_print(client,F("<br><br>"));

  //if (web_server_incoming_string.length() > 14){web_server_incoming_string.remove(14);}

  if ((web_server_incoming_string.indexOf("?m") > 0) && (web_server_incoming_string.length() > (web_server_incoming_string.indexOf("?m")+2))) {
    memory_number_to_send = ((web_server_incoming_string.charAt(web_server_incoming_string.indexOf("?m")+2)-48)*10) + (web_server_incoming_string.charAt(web_server_incoming_string.indexOf("?m")+3)-48);


// web_client_print(client,web_server_incoming_string);
// web_client_print(client,F("<br><br>"));

// web_client_print(client,F("mem number: "));
// web_client_print(client,memory_number_to_send);
// web_client_print(client,F("<br><br>"));

// web_client_print(client,web_server_incoming_string.charAt(web_server_incoming_string.indexOf("?m")+1));
// web_client_print(client,web_server_incoming_string.charAt(web_server_incoming_string.indexOf("?m")+2));
// web_client_print(client,F("<br><br>"));

    add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
    add_to_send_buffer(memory_number_to_send-1);
  }


  for(int i = 0;i < number_of_memories;i++){
    web_client_print(client,F("<a href=\"/mem?m"));
    if(i < 9){web_client_print(client,"0");}
    web_client_print(client,i+1);
    web_client_print(client,"\" class=\"ctrl\">");
    web_client_print(client,i+1);



    last_memory_location = memory_end(i) + 1;

    if (EEPROM.read(memory_start(i)) == 255) {
      // web_client_print(client,F("{empty}"));
      web_client_print(client,F("       "));
    } else {
      web_client_print(client,") ");
      for (int y = (memory_start(i)); (y < last_memory_location); y++) {
        if (EEPROM.read(y) < 255) {
          #if defined(OPTION_PROSIGN_SUPPORT)
            eeprom_temp = EEPROM.read(y);
            if ((eeprom_temp > PROSIGN_START) && (eeprom_temp < PROSIGN_END)){
              prosign_temp = convert_prosign(eeprom_temp);
              web_client_write(client,prosign_temp[0]);
              web_client_write(client,prosign_temp[1]);
              if(strlen(prosign_temp) == 3) web_client_write(client,prosign_temp[2]);
            } else {
              web_client_write(client,eeprom_temp);
            }
          #else
            web_client_write(client,EEPROM.read(y));
          #endif //OPTION_PROSIGN_SUPPORT
        } else {
          y = last_memory_location;
        }
      }
    }


    web_client_print(client,"</a>");
    // web_client_print(client,"<br><br><br>");
    if (number_of_memories > 4){
      if (((i+1) % 4) == 0){web_client_print(client,"<br><br><br>");}
    }
  }

  web_client_print(client,F("<br>"));

  web_print_home_link(client);

  web_print_footer(client);




}
#endif //FEATURE_WEB_SERVER && FEATURE_MEMORIES


//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)

void web_print_page_control(NETWORK_CLIENT_CLS client){

  /*

    /ctrl - regular page

    /ctrlnd - no display

    /ctrlnd?st<TEXTTOSEND>/

    http://192.168.1.178/ctrlnd?sttest/


  */

  uint8_t pin_read = 0;

  #if defined(FEATURE_MEMORIES)
    uint8_t memory_number_to_send = 0;
  #endif //FEATURE_MEMORIES

  int search_string_start_position = 0;

  String url_sub_string;

  if ((web_server_incoming_string.indexOf("ctrl?") > 0) || (web_server_incoming_string.indexOf("ctrlnd?") > 0)){
    url_sub_string = web_server_incoming_string;
    if (url_sub_string.length() > 14){url_sub_string.remove(14);}
    if (url_sub_string.indexOf("?ky") > 0){
      sending_mode = AUTOMATIC_SENDING;
      web_control_tx_key_time = millis();
      tx_and_sidetone_key(1);
    }
    if (url_sub_string.indexOf("?uk") > 0){
      sending_mode = AUTOMATIC_SENDING;
      tx_and_sidetone_key(0);
      web_control_tx_key_time = 0;
    }
    if (url_sub_string.indexOf("?wn") > 0){
      speed_change(-2);
    }
    if (url_sub_string.indexOf("?wp") > 0){
      speed_change(2);
    }
    #if defined(FEATURE_MEMORIES)
      if ((web_server_incoming_string.indexOf("?m") > 0) & (web_server_incoming_string.length() > (web_server_incoming_string.indexOf("?m")+2))) {
        memory_number_to_send = ((web_server_incoming_string.charAt(web_server_incoming_string.indexOf("m")+1)-48)*10) + (web_server_incoming_string.charAt(web_server_incoming_string.indexOf("m")+2)-48);
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(memory_number_to_send-1);
      }
    #endif //FEATURE_MEMORIES
    if (url_sub_string.indexOf("?st") > 0){
      for (int x = (web_server_incoming_string.indexOf("st")+2);x < web_server_incoming_string.length();x++){
        if (web_server_incoming_string.charAt(x) == '/'){
          x = web_server_incoming_string.length();
        } else {
          if (web_server_incoming_string.charAt(x) == '%'){  // do we have a http hex code?
            add_to_send_buffer((((uint8_t)web_server_incoming_string.charAt(x+1)-48)<<4)+((uint8_t)web_server_incoming_string.charAt(x+2)-48));
            x = x + 2;
          } else {
            add_to_send_buffer(uppercase(web_server_incoming_string.charAt(x)));
          }
        }
      }
    }
  }



  if (web_server_incoming_string.indexOf("nd") > 0){ // no display option

    web_print_200OK(client);

  } else {

    web_print_header(client);

    web_print_style_sheet(client);

    web_print_title(client);

    web_client_println(client,F("<H1>Control</H1><hr><br>"));


// web_client_print(client,"web_server_incoming_string: ");
// web_client_print(client,web_server_incoming_string);
// web_client_print(client,"url_sub_string: ");
// web_client_print(client,url_sub_string);
// web_client_println(client,F("<br><br>"));

    #if defined(FEATURE_MEMORIES)
    web_client_print(client,F("<br><br>"));
    for(int i = 0;i < number_of_memories;i++){
      web_client_print(client,F("<a href=\"/ctrl?m"));
      if(i < 9){web_client_print(client,"0");}
      web_client_print(client,i+1);
      web_client_print(client,"\" class=\"ctrl\">");
      web_client_print(client,i+1);
      web_client_print(client,"</a>");
      if (number_of_memories > 4){
        if (((i+1) % 4) == 0){web_client_print(client,"<br><br><br>");}
      }
    }

    web_client_print(client,F("<br>"));

    #endif //FEATURE_MEMORIES

    web_client_println(client,F("<br><a href=\"/ctrl?wn\" class=\"ctrl\">WPM -2</a><a href=\"/ctrl?wp\" class=\"ctrl\">WPM +2</a><br><br><br>"));

    web_client_println(client,F("<br><a href=\"/ctrl?ky\" class=\"ctrl\">Key</a><a href=\"/ctrl?uk\" class=\"ctrl\">Unkey</a><br><br><br>"));

    web_print_home_link(client);

    web_print_footer(client);

  }



}
#endif //FEATURE_WEB_SERVER


//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_println(NETWORK_CLIENT_CLS client,const __FlashStringHelper *str){

  web_client_print(client,str);
  client.println();

}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(NETWORK_CLIENT_CLS client,const __FlashStringHelper *str){

  char c;
  if(!str) return;
  char charstring[255] = "";
  int charstringindex = 0;

  /* since str is a const we can't increment it, so do this instead */
  char *p = (char *)str;

  /* keep going until we find the null */
  while((c = pgm_read_byte(p++))){
    if (charstringindex < 254){
      charstring[charstringindex] = c;
      charstringindex++;
    }

  }
  charstring[charstringindex] = 0;
  client.print(charstring);

}

#endif //FEATURE_WEB_SERVER


//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(NETWORK_CLIENT_CLS client,String str){

  client.print(str);

}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(NETWORK_CLIENT_CLS client,const char *str){

  client.print(str);

}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_println(NETWORK_CLIENT_CLS client,const char *str){

  client.println(str);

}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(NETWORK_CLIENT_CLS client,int i){

  client.print(i);

}
#endif //FEATURE_WEB_SERVER



//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(NETWORK_CLIENT_CLS client,float f){

  client.print(f);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(NETWORK_CLIENT_CLS client,unsigned long i){

  client.print(i);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(NETWORK_CLIENT_CLS client,unsigned int i){

  client.print(i);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_println(NETWORK_CLIENT_CLS client,unsigned long i){

  client.println(i);

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_println(NETWORK_CLIENT_CLS client,unsigned long i,int something){

  client.println(i,something);

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_write(NETWORK_CLIENT_CLS client,uint8_t i){

  client.write(i);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_link_settings_process(NETWORK_CLIENT_CLS client){

#if defined(FEATURE_INTERNET_LINK)
  uint8_t parsed_link_ip[4][FEATURE_INTERNET_LINK_MAX_LINKS];
  uint8_t parsed_link_enabled[FEATURE_INTERNET_LINK_MAX_LINKS];
  int parsed_link_send_udp_port[FEATURE_INTERNET_LINK_MAX_LINKS];
  int parsed_link_receive_udp_port = 0;
  uint8_t parsed_link_receive_enabled = 0;


  uint8_t invalid_data = 0;

  unsigned int ud = 0;

  parse_get(web_server_incoming_string);
  if (parse_get_results_index){

    for (int x = 0; x < parse_get_results_index; x++){   // TODO - rewrite this to scale...
      if (parse_get_results[x].parameter == "ip00"){parsed_link_ip[0][0] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip01"){parsed_link_ip[1][0] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip02"){parsed_link_ip[2][0] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip03"){parsed_link_ip[3][0] = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "ip10"){parsed_link_ip[0][1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip11"){parsed_link_ip[1][1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip12"){parsed_link_ip[2][1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip13"){parsed_link_ip[3][1] = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "ip20"){parsed_link_ip[0][2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip21"){parsed_link_ip[1][2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip22"){parsed_link_ip[2][2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip23"){parsed_link_ip[3][2] = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "act0"){parsed_link_enabled[0] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "act1"){parsed_link_enabled[1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "act2"){parsed_link_enabled[2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "act3"){parsed_link_enabled[3] = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "sp0"){parsed_link_send_udp_port[0] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sp1"){parsed_link_send_udp_port[1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sp2"){parsed_link_send_udp_port[2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sp3"){parsed_link_send_udp_port[3] = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "ud"){parsed_link_receive_udp_port = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "lr"){parsed_link_receive_enabled = parse_get_results[x].value_long;}

    }


    // data validation

    for (int x = 0;x < FEATURE_INTERNET_LINK_MAX_LINKS;x++){
      if (parsed_link_enabled[x]){
        for (int y = 0;y < 4;y++){
          if ((parsed_link_ip[y][x] < 0) || (parsed_link_ip[y][x] > 255)){
            invalid_data = 1;
          }
        }
        if ((parsed_link_ip[3][x] == 0) || (parsed_link_ip[3][x] == 255) || (parsed_link_ip[0][x] == 0) || (parsed_link_ip[0][x] == 255)){
          invalid_data = 1;
        }
        if ((parsed_link_send_udp_port[x] < 1) || (parsed_link_send_udp_port[x] > 65535)){
          invalid_data = 1;
        }
      }
    }


    if (invalid_data){

      web_print_header(client);
#if defined(FEATURE_ETHERNET)
      web_print_meta_refresh(client,configuration.ip[0],configuration.ip[1],configuration.ip[2],configuration.ip[3],2);
#endif
      web_client_println(client,F("\/LinkSettings'\" />"));
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Bad data!<br>"));
      web_print_home_link(client);
      web_print_footer(client);

    } else {

      for (int x = 0;x < FEATURE_INTERNET_LINK_MAX_LINKS;x++){

        configuration.link_send_ip[0][x] = parsed_link_ip[0][x];
        configuration.link_send_ip[1][x] = parsed_link_ip[1][x];
        configuration.link_send_ip[2][x] = parsed_link_ip[2][x];
        configuration.link_send_ip[3][x] = parsed_link_ip[3][x];

        configuration.link_send_udp_port[x] = parsed_link_send_udp_port[x];

        configuration.link_send_enabled[x] = parsed_link_enabled[x];
      }

      configuration.link_receive_udp_port = parsed_link_receive_udp_port;
      configuration.link_receive_enabled = parsed_link_receive_enabled;


      web_print_header(client);
      web_print_meta_refresh(client,configuration.ip[0],configuration.ip[1],configuration.ip[2],configuration.ip[3],5);
      web_client_println(client,F("\/LinkSettings'\" />"));
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Configuration saved<br><br>"));
      web_print_home_link(client);
      web_print_footer(client);
      config_dirty = 1;
    }
  }
#else
  web_print_header(client);
  web_client_println(client,F("<br>Feature internet links not enabled.<br><br>"));
  web_print_home_link(client);
  web_print_footer(client);
#endif //FEATURE_INTERNET_LINK
}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_network_settings_process(NETWORK_CLIENT_CLS client){

#if defined(FEATURE_WIFI)
  // hier wifi auswertung
  char wifi_ssid_buffer[sizeof(configuration.wifi_ssid)];
  char wifi_password_buffer[sizeof(configuration.wifi_password)];

  memset(wifi_ssid_buffer, 0, sizeof(wifi_ssid_buffer));
  memset(wifi_password_buffer, 0, sizeof(wifi_password_buffer));
#else
  uint8_t ip0 = 0;
  uint8_t ip1 = 0;
  uint8_t ip2 = 0;
  uint8_t ip3 = 0;
  uint8_t gw0 = 0;
  uint8_t gw1 = 0;
  uint8_t gw2 = 0;
  uint8_t gw3 = 0;
  uint8_t sn0 = 0;
  uint8_t sn1 = 0;
  uint8_t sn2 = 0;
  uint8_t sn3 = 0;
#endif

  uint8_t invalid_data = 0;

  unsigned int ud = 0;

  parse_get(web_server_incoming_string);
  if (parse_get_results_index){
    for (int x = 0; x < parse_get_results_index; x++){
#if defined(FEATURE_WIFI)

      if (parse_get_results[x].parameter == "wifi_ssid") {
        if (parse_get_results[x].value_string.length() >= sizeof(wifi_ssid_buffer)) {
          invalid_data = 1;
        } else {
          parse_get_results[x].value_string.toCharArray(
            wifi_ssid_buffer,
            sizeof(wifi_ssid_buffer)
          );
        }
      }

      if (parse_get_results[x].parameter == "wifi_pwd") {
        if (parse_get_results[x].value_string.length() >= sizeof(wifi_password_buffer)) {
          invalid_data = 1;
        } else {
          parse_get_results[x].value_string.toCharArray(
            wifi_password_buffer,
            sizeof(wifi_password_buffer)
          );
        }
      }
#else
      if (parse_get_results[x].parameter == "ip0"){ip0 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip1"){ip1 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip2"){ip2 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip3"){ip3 = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "gw0"){gw0 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "gw1"){gw1 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "gw2"){gw2 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "gw3"){gw3 = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "sn0"){sn0 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sn1"){sn1 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sn2"){sn2 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sn3"){sn3 = parse_get_results[x].value_long;}
#endif

    }

    //invalid_data = 1;


    // data validation
#if defined(FEATURE_WIFI)
#else
    if ((ip0 == 0) || (ip3 == 255) || (ip3 == 0)) {invalid_data = 1;}
    if (((ip0 & sn0) != (gw0 & sn0)) || ((ip1 & sn1) != (gw1 & sn1)) || ((ip2 & sn2) != (gw2 & sn2)) || ((ip3 & sn3) != (gw3 & sn3))) {invalid_data = 1;}
    if ((sn0 == 0) || (sn1 > sn0) || (sn2 > sn1) || (sn3 > sn2) || (sn3 > 252)) {invalid_data = 1;}
#endif
    if (invalid_data){

      web_print_header(client);
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Bad data!<br>"));
      web_print_home_link(client);
      web_print_footer(client);

    } else {
#if defined(FEATURE_ETHERNET)
      configuration.ip[0] = ip0;
      configuration.ip[1] = ip1;
      configuration.ip[2] = ip2;
      configuration.ip[3] = ip3;

      configuration.gateway[0] = gw0;
      configuration.gateway[1] = gw1;
      configuration.gateway[2] = gw2;
      configuration.gateway[3] = gw3;

      configuration.subnet[0] = sn0;
      configuration.subnet[1] = sn1;
      configuration.subnet[2] = sn2;
      configuration.subnet[3] = sn3;


      web_print_header(client);
      web_print_meta_refresh(client,ip0,ip1,ip2,ip3,5);
      web_client_println(client,F("'\" />"));
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Configuration saved<br>Restarting networking<br><br>You will be redirected to new address in 5 seconds...<br>"));
      web_print_home_link(client);
      web_print_footer(client);
      restart_networking = 1;
      config_dirty = 1;
#elif defined(FEATURE_WIFI)
      memset(configuration.wifi_ssid, 0, sizeof(configuration.wifi_ssid));
      memset(configuration.wifi_password, 0, sizeof(configuration.wifi_password));

      memcpy(
        configuration.wifi_ssid,
        wifi_ssid_buffer,
        sizeof(configuration.wifi_ssid)
      );

      memcpy(
        configuration.wifi_password,
        wifi_password_buffer,
        sizeof(configuration.wifi_password)
      );
#if defined(DEBUG_WIFI)
      debug_serial_port->print("SSID: ");
      debug_serial_port->println(configuration.wifi_ssid);
      debug_serial_port->print("WIFIPW: ");
      debug_serial_port->println(configuration.wifi_password);
#endif

      web_print_header(client);
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>WiFi configuration saved<br>Restarting WiFi<br><br>"));
      web_print_home_link(client);
      web_print_footer(client);

      config_dirty = 1;

      initialize_wifi();
#else
      web_print_header(client);
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Ethernet or Wifi not enabled?!<br>"));
      web_print_home_link(client);
      web_print_footer(client);
#endif
    }
  }
}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_meta_refresh(NETWORK_CLIENT_CLS client,uint8_t ip0,uint8_t ip1,uint8_t ip2,uint8_t ip3,uint8_t refresh_time){

  web_client_print(client,F("<meta http-equiv=\"refresh\" content=\""));
  web_client_print(client,refresh_time);
  web_client_print(client,F("; URL='http://"));
  web_client_print(client,ip0);
  web_client_print(client,".");
  web_client_print(client,ip1);
  web_client_print(client,".");
  web_client_print(client,ip2);
  web_client_print(client,".");
  web_client_print(client,ip3);

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
