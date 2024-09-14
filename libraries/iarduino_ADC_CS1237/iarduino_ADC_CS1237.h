//	Библиотека для работы с одноканальным дифференциальным АЦП CS1237: http://iarduino.ru/
//  Версия: 1.0.4
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/
//  Подробное описание функции бибилиотеки доступно по ссылке: http://wiki.iarduino.ru/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef iarduino_ADC_CS1237_h
#define iarduino_ADC_CS1237_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class	iarduino_ADC_CS1237{
	public:			iarduino_ADC_CS1237	(uint8_t SCLK, uint8_t DATA)		//	Конструктор красса.							(вывод SCLK, вывод DATA)
										{pinSCL= SCLK; pinSDA= DATA;}		//
																			//
		bool		begin				(void);								//	Инициализация модуля.						(без параметров)
		int32_t		analogRead			(void);								//	Чтение знакового значения АЦП.				(без параметров)
		float		getVoltage			(void);								//	Получить напряжение зная Vref_in.			(без параметров)
																			//
		bool		setPinVrefOut		(bool		pinVrefOut_ON	);		//	Управление выводом REF_OUT.					(true=ON/false=OFF) На включённом выходе VrefOut появится сглаженное напряжение Vcc чипа, которое можно подать на вход VrefIn.
		bool		setSpeed			(uint16_t	Speed			);		//	Выбор скорости преобразований в Гц.			(10,40,640,1280)    Частота готовности новых данных для чтения.
		bool		setPGA				(uint8_t	PGA				);		//	Выбор коэффициента усиления.				(1,2,64,128)        Измеряемые напряжения лежат в диапазоне ± 0,5 VrefIn / PGA.
		bool		setChannel			(uint8_t	Channel			);		//	Выбор канала АЦП.							(0,2,3)             0-Канал А, 1-Резерв, 2-Температура, 3-Внутреннее короткое замыкание.
		bool		setPulseWidth		(uint8_t	Width			);		//	Установить ширину импульсов в мкс.			(1 ... 255)			Длительность импульсов и пауз на линии SCL.
		bool		setVrefIn			(float		Vref_in			);		//	Указать напряжение на входе Vref_in.		(1.5 ... Vcc+0.1)
																			//
		bool		getPinVrefOut		(void);								//	Получить состояние вывода REF_OUT.			(без параметров)
		uint16_t	getSpeed			(void);								//	Получить текущую скорость преобразований.	(без параметров)
		uint8_t		getPGA				(void);								//	Получить текущий коэффициент усиления.		(без параметров)
		uint8_t		getChannel			(void);								//	Получить используемый канал АЦП.			(без параметров)
		uint8_t		getPulseWidth		(void){ return timDelay;	}		//	Получить ширину импульсов в мкс.			(без параметров)
		float		getVrefIn			(void){ return valVref;		}		//	Получить Vref указанное в setVrefIn().		(без параметров)
																			//
	private:																//
		uint8_t		pinSCL			=	255;								//	Вывод линии тактирования.
		uint8_t		pinSDA			=	255;								//	Вывод линии данных.
		uint8_t		timDelay		=	5;									//	Длительность импульсов и пауз SCL в мкс.
		bool		flgPinVrefOut	=	1;									//	Состояние вывода REF_OUT.
		uint16_t	valSpeed		=	10;									//	Скорость преобразований.
		uint8_t		valPGA			=	128;								//	Коэффициент усиления.
		uint8_t		valChannel		=	0;									//	Используемый канал АЦП.
		float		valVref			=	5.0f;								//	Опорное напряжение на входе Vref_in.
																			//
		bool		_waitDataReady		(void);								//	Ожидание готовности данных.					(без параметров)
		void		_pinModeSCL			(int);								//	Конфигурация вывода SCL.					(INPUT/OUTPUT)
		void		_pinModeSDA			(int);								//	Конфигурация вывода SDA.					(INPUT/OUTPUT)
		bool		_readBit			(void);								//	Чтение одного бита данных.
		void		_writeBit			(bool);								//	Запист одного бита данных.
		int32_t		_readADC			(void);								//	Чтение данных АЦП.							(без параметров)
		bool		_regConfig			(bool);								//	Чтение/запись конфигурационного регистра.	(CS1237_REG_READ/CS1237_REG_WRITE)
};

#endif
