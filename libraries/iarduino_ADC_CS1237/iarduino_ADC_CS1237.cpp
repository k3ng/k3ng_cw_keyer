#include "iarduino_ADC_CS1237.h"													//
																					//
#define CS1237_REG_WRITE 0															//
#define CS1237_REG_READ  1															//
																					//
//		ИНИЦИАЛИЗАЦИЯ МОДУЛЯ:														//	ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ: РЕЗУЛЬТАТ ИНИЦИАЛИЗАЦИИ.
bool	iarduino_ADC_CS1237::begin(void){											//	Параметр: отсутствует
		//	Конфигурируем выводы SCL, SDA:											//
			_pinModeSCL(OUTPUT);													//
			_pinModeSDA(INPUT);														//
			return _regConfig(CS1237_REG_READ);										//	Возвращаем флаг успеха чтения конфигурационного регистра.
}																					//
																					//
//		ЧТЕНИЕ ЗНАКОВОГО ЗНАЧЕНИЯ АЦП:												//
int32_t	iarduino_ADC_CS1237::analogRead(void){										//
			if( !_waitDataReady() ){ return 0; }									//	Ждём готовности данных. Если данные не готовы, возвращаем 0.
			return _readADC();														//	Возвращаем результат преобразований АЦП.
}																					//
																					//
//		ПОЛУЧИТЬ НАПРЯЖЕНИЕ ЗНАЯ VREF:												//
float	iarduino_ADC_CS1237::getVoltage(void){										//
			return (float)analogRead()*valVref/16777215/valPGA;						//	ΔV = ADC * Vref / (2^24-1) / PGA.
}																					//
																					//
//		УСТАНОВИТЬ ШИРИНУ ИМПУЛЬСОВ В МКС:											//
bool	iarduino_ADC_CS1237::setPulseWidth(uint8_t i){ timDelay=i; return true; }	//	Сохраняем timDelay которое хранит ширину импульсов и пауз на линии SCL.
//		УКАЗАТЬ НАПРЯЖЕНИЕ НА ВХОДЕ VREF_IN:										//
bool	iarduino_ADC_CS1237::setVrefIn(float i){ valVref=i; return true; }			//	Сохраняем Vref_IN которое должно находиться в диапазоне от 1.5 В, до Vcc-0.1 В.
																					//
//		ЗАПИСАТЬ ЗНАЧЕНИЕ В КОНФИГУРАЦИОННЫЙ РЕГИСТР:								//
bool	iarduino_ADC_CS1237::setPinVrefOut(bool     i){flgPinVrefOut=i; return _regConfig(CS1237_REG_WRITE); }	//	Управление выводом REF_OUT.		(true=ON/false=OFF)
bool	iarduino_ADC_CS1237::setSpeed     (uint16_t i){valSpeed     =i; return _regConfig(CS1237_REG_WRITE); }	//	Выбор скорости преобразований.	(10,40,640,1280)
bool	iarduino_ADC_CS1237::setPGA       (uint8_t  i){valPGA       =i; return _regConfig(CS1237_REG_WRITE); }	//	Выбор коэффициента усиления.	(1,2,64,128)
bool	iarduino_ADC_CS1237::setChannel   (uint8_t  i){valChannel   =i; return _regConfig(CS1237_REG_WRITE); }	//	Выбор канала АЦП.				(0,1,2,3)
																					//
//		ПОЛУЧИТЬ ЗНАЧЕНИЕ ИЗ КОНФИГУРАЦИОННОГО РЕГИСТРА:							//
bool	 iarduino_ADC_CS1237::getPinVrefOut(void){ _regConfig(CS1237_REG_READ); return flgPinVrefOut; }	//	Получить состояние вывода REF_OUT.
uint16_t iarduino_ADC_CS1237::getSpeed     (void){ _regConfig(CS1237_REG_READ); return valSpeed;      }	//	Получить текущую скорость преобразований.
uint8_t	 iarduino_ADC_CS1237::getPGA       (void){ _regConfig(CS1237_REG_READ); return valPGA;        }	//	Получить текущий коэффициент усиления.
uint8_t	 iarduino_ADC_CS1237::getChannel   (void){ _regConfig(CS1237_REG_READ); return valChannel;    }	//	Получить используемый канал АЦП.
																					//
//		ОЖИДАНИЕ ГОТОВНОСТИ ДАННЫХ:													//
bool	iarduino_ADC_CS1237::_waitDataReady(void){									//
			bool i,j; uint32_t k;													//	i=логический уровень, j=флаг наличия времени, k=время начала ожидания уровня.
		//  Ждём появление импульса на выводе SDA:									//	Согласно datasheet готовность первых данных после подачи питания или изменения конфигурации: 300мс для 10Гц, 75мс для 40Гц, 6.25мс для 640Гц, 3.125мс для 1280Гц.
			k=millis();																//
			do{ i=digitalRead(pinSDA); j=(millis()-k)<500; } while( i==0 && j );	//	Ждём установки высокого уровня на линии SDA. Выходим из цикла при появлении ожидаемого уровня i, или при превышении времени !j.
			if( !j ){ return j; }													//	Возвращаем флаг ошибки.
		//  Ждём сброса импульса на выводе SDA:										//	Согласно datasheet длительность импульса готовности данных составляет 26.13мкс.
			k=millis();																//
			do{ i=digitalRead(pinSDA); j=(millis()-k)<500; } while( i==1 && j );	//	Ждём установки низкого уровня на линии SDA. Выходим из цикла при появлении ожидаемого уровня i, или при превышении времени !j.
			return j;																//	Возвращаем флаг результата готовности данных
}																					//
																					//
//		КОНФИГУРАЦИЯ ВЫВОДА SCL:													//
void	iarduino_ADC_CS1237::_pinModeSCL(int i){									//
			pinMode(pinSCL, i); digitalWrite(pinSCL, 0);							//	Переконфигурируем вывод pinSDA Arduino на работу в качестве выхода или выхода.
}																					//
																					//
//		КОНФИГУРАЦИЯ ВЫВОДА SDA:													//
void	iarduino_ADC_CS1237::_pinModeSDA(int i){									//
			if( i==OUTPUT ){ digitalWrite(pinSDA, 1); } pinMode(pinSDA, i);			//	Переконфигурируем вывод pinSDA Arduino на работу в качестве выхода или выхода.
}																					//
																					//
//		ЧТЕНИЕ ОДНОГО БИТА ДАННЫХ:													//
bool	iarduino_ADC_CS1237::_readBit(void){										//	        __    __
			bool i;																	//	SCL: __|  |__|
			delayMicroseconds(timDelay); digitalWrite(pinSCL, 1);					//	     __ __:__ __
			delayMicroseconds(timDelay); i=digitalRead(pinSDA);						//	SDA: __|_____|__
			                             digitalWrite(pinSCL, 0);					//            :
			return i;																//            ^  Чтение
}																					//
																					//
//		ЗАПИСЬ ОДНОГО БИТА ДАННЫХ:													//	        __    __
void	iarduino_ADC_CS1237::_writeBit(bool i){										//	SCL: __|  |__|
			digitalWrite(pinSDA, i);												//	     :____:____
			delayMicroseconds(timDelay); digitalWrite(pinSCL, 1);					//	SDA: |____|____|
			delayMicroseconds(timDelay); digitalWrite(pinSCL, 0);					//       ^    ^  Установка
}																					//
																					//
//		ЧТЕНИЕ ДАННЫХ АЦП:															//
int32_t	iarduino_ADC_CS1237::_readADC(void){										//
			int32_t i=0;															//
			uint8_t j=24; while(j--){ i <<= 1; i |= _readBit(); }					//	24 такта - получение 24 битов данных (старшим битом вперёд).
			if( i & 0x00800000 ){ i |= 0xFF800000; }								//	Если установлен старший (23) бит, то устанавливаем биты 31...24 - отрицательное число.
			return i;																//
}																					//
																					//
//		ЧТЕНИЕ/ЗАПИСЬ КОНФИГУРАЦИОННОГО РЕГИСТРА:									//	Функция вызывается сразу после _readADC().
bool	iarduino_ADC_CS1237::_regConfig(bool f){									//	f=1 (CS1237_REG_READ) - чтение регистра, f=0 (CS1237_REG_WRITE) - запись в регистр.
			uint8_t i, j, command = (f==CS1237_REG_READ)? 0x56:0x65;				//	j=данные конфигурационного регистра, command=команда чтения 0x56 или записи 0x65.
		//	Ждём готовности данных чипа:											//
			if( !_waitDataReady() ){ return false; }								//	О готовности данных свидетельствует положительный импульс. Если данные не готовы, возвращаем false.
		//	Читаем 24 бита АЦП:														//
			_readADC(); 															//	24 такта - получение АЦП.
		//	Читаем биты Update:														//
             _readBit();															//	25 такт - получение бита Update 1. Бит указывает на успех последней записи данных в конфигурационный регистр, сбрасывается при чтении регистра.
             _readBit();															//	26 такт - получение бита Update 2. Бит зарезервирован.
             _readBit();															//	27 такт - указываем чипу установить 1 на линии SDA (по фронту 27 такта).
		//	Указываем чипу переконфигурировать вывод SDA на вход:					//
			_readBit();																//	28 такт - информируем чип о желании чтения/записи конфигурационного регистра.
			_readBit();																//	29 такт - по спаду такта, вывод SDA чипа станет входом для получения команды.
		//	Отправляем командное слово:												//
			_pinModeSDA(OUTPUT);													//	Переконфигурируем вывод pinSDA Arduino на работу в качестве выхода.
			for( i=1; i<8; i++){ _writeBit( (command<<i) & 0x80 ); }				//	7 тактов - передача командного слова (старшим битом вперёд).
		//	Готовимся к чтению/записи данных:										//
			if( f==CS1237_REG_READ ){ _pinModeSDA(INPUT); }							//	Если мы читаем конфигурационный регистр, то переводим вывод pinSDA Arduino на работу в качестве входа.
			_readBit();																//	37 такт - по фронту такта, вывод SDA чипа станет входом или выходом, в зависимости от ранее переданного командного слова.
		//  Выполняем чтение/запись данных:											//
			if( f==CS1237_REG_READ ){												//
			//	Читаем конфигурационный регистр:									//
				j=0; for(i=0; i<8; i++){ j<<=1; j|=_readBit(); }					//	8 тактов - получение 8 бит данных из конфигурационного регистра (старшим битом вперёд).
			//	Сохраняем полученные данные:										//
				i=(j&0x40);    flgPinVrefOut = !i;									//	Состояние вывода REF_OUT хранится в 6 бите.
				i=(j&0x30)>>4; valSpeed      = (i==3?1280:(i==2?640:(i==1?40:10)));	//	Скорость преобразований хранится в 5 и 4 битах.
				i=(j&0x0C)>>2; valPGA        = (i==3?128 :(i==2?64 :(i==1?2 :1 )));	//	Коэффициент усиления хранится в 3 и 2 битах.
				i=(j&0x03);    valChannel    =  i;									//	Используемый канал АЦП хранится в 1 и 0 битах.
			}else{																	//
			//	Собираем данные для передачи:										//
				j=(flgPinVrefOut?0:0x40) | (valChannel&0x03);						//	Состояние вывода REF_OUT хранится в 6 бите, а канал АЦП в битах 1 и 0.
				i=(valSpeed==1280?3:(valSpeed==640?2:(valSpeed==40?1:0))); j|=i<<4;	//	Скорость преобразований хранится в 5 и 4 битах.
				i=(valPGA  ==128 ?3:(valPGA  ==64 ?2:(valPGA  ==2 ?1:0))); j|=i<<2;	//	Коэффициент усиления хранится в 3 и 2 битах.
			//	Записываем данные в конфигурационный регистр:						//
				for(i=0; i<8; i++){ _writeBit( (j<<i) & 0x80 ); }					//	8 тактов - передача 8 бит данных в конфигурационный регистр (старшим битом вперёд).
			}																		//
		//	Завершаем чтение/запись данных:											//
			_pinModeSDA(INPUT);														//	Переконфигурируем вывод pinSDA Arduino на работу в качестве входа.
			_readBit();																//	46 такт - по фронту такта, вывод SDA чипа станет выходом и на нём установится уровень логической 1.
		//	Проверяем корректность чтения/записи данных:							//
			return true;															//
}																					//
