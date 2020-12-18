#include "tsushinn.h"

DualShock3::DualShock3(PinName tx, PinName rx, int bps){
	SCI = new UnbufferedSerial(tx, rx, bps);
	SCI->format(8, SerialBase::None, 1);
	//SCI->baud(bps);
	SCI->attach(callback(this,&DualShock3::DataReceive), UnbufferedSerial::RxIrq);
}

void DualShock3::StateHold(void){

	if(Update){

		Update = 0;
		getButton();
		getJoyStick();
		/*Circle.press   = Circle.press_storage
		Cross.press    = Cross.press_storage
		Triangle.press = Triangle.press_storage
		Square.press   = Square.press_storage
		Up.press       = Up.press_storage
		Down.press     = Down.press_storage
		Left.press     = Left.press_storage
		Right.press    = Right.press_storage
		L1.press 	   = L1.press_storage
		R1.press 	   = R1.press_storage
		L3.press 	   = L3.press_storage
		R3.press 	   = R3.press_storage
		Select.press   = Select.press_storage
		Start.press    = Start.press_storage
		PS.press       = PS.press_storage
		L2.press 	   = L2.press_storage
		R2.press 	   = R2.press_storage

		Circle.count   = Circle.count_storage
		Cross.count    = Cross.count_storage
		Triangle.count = Triangle.count_storage
		Square.count   = Square.count_storage
		Up.count 	   = Up.count_storage
		Down.count     = Down.count_storage
		Left.count     = Left.count_storage
		Right.count    = Right.count_storage
		L1.count	   = L1.count_storage
		R1.count	   = R1.count_storage
		L3.count	   = L3.count_storage
		R3.count	   = R3.count_storage
		Select.count   = Select.count_storage
		Start.count    = Start.count_storage
		PS.count       = PS.count_storage
		L2.count	   = L2.count_storage
		R2.count	   = R2.count_storage

		Circle.toggle 	= Circle.count%2  //Circle.toggle_storage
		Cross.toggle	= Cross.count%2   //Cross.toggle_storage
		Triangle.toggle = Triangle.count%2//Triangle.toggle_storage
		Square.toggle 	= Square.count%2  //Square.toggle_storage
		Up.toggle 		= Up.count%2 	  //Up.toggle_storage
		Down.toggle 	= Down.count%2    //Down.toggle_storage
		Left.toggle 	= Left.count%2    //Left.toggle_storage
		Right.toggle 	= Right.count%2   //Right.toggle_storage
		L1.toggle 		= L1.count%2	  //L1.toggle_storage
		R1.toggle 		= R1.count%2	  //R1.toggle_storage
		L3.toggle 		= L3.count%2	  //L3.toggle_storage
		R3.toggle 		= R3.count%2	  //R3.toggle_storage
		Select.toggle 	= Select.count%2  //Select.toggle_storage
		Start.toggle 	= Start.count%2   //Start.toggle_storage
		PS.toggle 		= PS.count%2      //PS.toggle_storage
		L2.toggle 		= L2.count%2	  //L2.toggle_storage
		R2.toggle 		= R2.count%2	  //R2.toggle_storage
		
		Circle.pressure   = 0;
		Cross.pressure 	  = 0;
		Triangle.pressure = 0;
		Square.pressure   = 0;
		Up.pressure 	  = 0;
		Down.pressure 	  = 0;
		Left.pressure 	  = 0;
		Right.pressure 	  = 0;
		L1.pressure		  = 0;
		R1.pressure		  = 0;
		L3.pressure		  = 0;
		R3.pressure		  = 0;
		Select.pressure   = 0;
		Start.pressure    = 0;
		PS.pressure 	  = 0;
		L2.pressure		  = (rx_data[4]&0xF0)-16;
		R2.pressure		  = (rx_data[5]&0xF0)-16;*/
		/*
		jsl.x = jsl.x_storage;
		jsl.y = jsl.y_storage;
		jsr.x = jsr.x_storage;
		jsr.y = jsr.y_storage;
		jsl.rad = getRadians(&jsl);
		jsr.rad = getRadians(&jsr);
		jsl.deg = getAngles(&jsl);
		jsr.deg = getAngles(&jsr);*/
	}
}

void DualShock3::getButton(void){

	Circle.press   = is(rx_data[0]&0x80);
	Cross.press    = is(rx_data[0]&0x40);
	Triangle.press = is(rx_data[0]&0x20);
	Square.press   = is(rx_data[0]&0x10);
	Up.press       = is(rx_data[1]&0x80);
	Down.press     = is(rx_data[1]&0x40);
	Left.press     = is(rx_data[1]&0x20);
	Right.press    = is(rx_data[1]&0x10);
	L1.press 	   = is(rx_data[2]&0x80);
	R1.press 	   = is(rx_data[2]&0x40);
	L3.press 	   = is(rx_data[2]&0x20);
	R3.press 	   = is(rx_data[2]&0x10);
	Select.press   = is(rx_data[3]&0x80);
	Start.press    = is(rx_data[3]&0x40);
	PS.press       = is(rx_data[3]&0x20);
	L2.press 	   = is(rx_data[4]&0xF0);
	R2.press 	   = is(rx_data[5]&0xF0);

	Circle.count   += pushCount(&Circle);
	Cross.count    += pushCount(&Cross);
	Triangle.count += pushCount(&Triangle);
	Square.count   += pushCount(&Square);
	Up.count 	   += pushCount(&Up);
	Down.count     += pushCount(&Down);
	Left.count     += pushCount(&Left);
	Right.count    += pushCount(&Right);
	L1.count	   += pushCount(&L1);
	R1.count	   += pushCount(&R1);
	L3.count	   += pushCount(&L3);
	R3.count	   += pushCount(&R3);
	Select.count   += pushCount(&Select);
	Start.count    += pushCount(&Start);
	PS.count       += pushCount(&PS);
	L2.count	   += pushCount(&L2);
	R2.count	   += pushCount(&R2);

	Circle.toggle 	= Circle.count%2;  //Circle.togg;
	Cross.toggle	= Cross.count%2;   //Cross.toggl;
	Triangle.toggle = Triangle.count%2;//Triangle.to;
	Square.toggle 	= Square.count%2;  //Square.togg;
	Up.toggle 		= Up.count%2; 	   //Up.toggle_s;
	Down.toggle 	= Down.count%2;    //Down.toggle;
	Left.toggle 	= Left.count%2;    //Left.toggle;
	Right.toggle 	= Right.count%2;   //Right.toggl;
	L1.toggle 		= L1.count%2;	   //L1.toggle_s;
	R1.toggle 		= R1.count%2;	   //R1.toggle_s;
	L3.toggle 		= L3.count%2;	   //L3.toggle_s;
	R3.toggle 		= R3.count%2;	   //R3.toggle_s;
	Select.toggle 	= Select.count%2;  //Select.togg;
	Start.toggle 	= Start.count%2;   //Start.toggl;
	PS.toggle 		= PS.count%2;      //PS.toggle_s;
	L2.toggle 		= L2.count%2;	   //L2.toggle_s;
	R2.toggle 		= R2.count%2;	   //R2.toggle_s;

	/*Circle.pressure   = 0;
	Cross.pressure 	  = 0;
	Triangle.pressure = 0;
	Square.pressure   = 0;
	Up.pressure 	  = 0;
	Down.pressure 	  = 0;
	Left.pressure 	  = 0;
	Right.pressure 	  = 0;
	L1.pressure		  = 0;
	R1.pressure		  = 0;
	L3.pressure		  = 0;
	R3.pressure		  = 0;
	Select.pressure   = 0;
	Start.pressure    = 0;
	PS.pressure 	  = 0;*/
	L2.pressure		  = getPressure((short)(rx_data[4]&0xF0) + (rx_data[5]>>4));
	R2.pressure		  = getPressure((short)(rx_data[6]&0xF0) + (rx_data[7]>>4));
	/*
	Circle.press_storage   = is(rx_data[0]&0x80);
	Cross.press_storage    = is(rx_data[0]&0x40);
	Triangle.press_storage = is(rx_data[0]&0x20);
	Square.press_storage   = is(rx_data[0]&0x10);
	Up.press_storage       = is(rx_data[1]&0x80);
	Down.press_storage     = is(rx_data[1]&0x40);
	Left.press_storage     = is(rx_data[1]&0x20);
	Right.press_storage    = is(rx_data[1]&0x10);
	L1.press_storage 	   = is(rx_data[2]&0x80);
	R1.press_storage 	   = is(rx_data[2]&0x40);
	L3.press_storage 	   = is(rx_data[2]&0x20);
	R3.press_storage 	   = is(rx_data[2]&0x10);
	Select.press_storage   = is(rx_data[3]&0x80);
	Start.press_storage    = is(rx_data[3]&0x40);
	PS.press_storage       = is(rx_data[3]&0x20);
	L2.press_storage 	   = is(rx_data[4]&0xF0);
	R2.press_storage 	   = is(rx_data[5]&0xF0);
	
	Circle.count_storage   += pushCount(&Circle);
	Cross.count_storage    += pushCount(&Cross);
	Triangle.count_storage += pushCount(&Triangle);
	Square.count_storage   += pushCount(&Square);
	Up.count_storage 	   += pushCount(&Up);
	Down.count_storage     += pushCount(&Down);
	Left.count_storage     += pushCount(&Left);
	Right.count_storage    += pushCount(&Right);
	L1.count_storage	   += pushCount(&L1);
	R1.count_storage	   += pushCount(&R1);
	L3.count_storage	   += pushCount(&L3);
	R3.count_storage	   += pushCount(&R3);
	Select.count_storage   += pushCount(&Select);
	Start.count_storage    += pushCount(&Start);
	PS.count_storage       += pushCount(&PS);
	L2.count_storage	   += pushCount(&L2);
	R2.count_storage	   += pushCount(&R2);

	Circle.toggle_storage 	= Circle.count_storage%2;
	Cross.toggle_storage	= Cross.count_storage%2;
	Triangle.toggle_storage = Triangle.count_storage%2;
	Square.toggle_storage 	= Square.count_storage%2;
	Up.toggle_storage 		= Up.count_storage%2;
	Down.toggle_storage 	= Down.count_storage%2;
	Left.toggle_storage 	= Left.count_storage%2;
	Right.toggle_storage 	= Right.count_storage%2;
	L1.toggle_storage 		= L1.count_storage%2;
	R1.toggle_storage 		= R1.count_storage%2;
	L3.toggle_storage 		= L3.count_storage%2;
	R3.toggle_storage 		= R3.count_storage%2;
	Select.toggle_storage 	= Select.count_storage%2;
	Start.toggle_storage 	= Start.count_storage%2;
	PS.toggle_storage 		= PS.count_storage%2;
	L2.toggle_storage 		= L2.count_storage%2;
	R2.toggle_storage 		= R2.count_storage%2;*/

	//L2.pressure_storage		  = (rx_data[4]&0xF0)-16;
	//R2.pressure_storage		  = (rx_data[5]&0xF0)-16;
}

void DualShock3::getJoyStick(void){

	jsl.x/*_storage*/ =  DeadBand((short)(rx_data[ 8]&0xF0) + (rx_data[9]>>4));
	jsl.y/*_storage*/ = -DeadBand((short)(rx_data[10]&0xF0) + (rx_data[11]>>4));
	jsr.x/*_storage*/ =  DeadBand((short)(rx_data[12]&0xF0) + (rx_data[13]>>4));
	jsr.y/*_storage*/ = -DeadBand((short)(rx_data[14]&0xF0) + (rx_data[15]>>4));
	jsl.rad = getRadians(&jsl);
	jsr.rad = getRadians(&jsr);
	jsl.deg = getAngles(&jsl);
	jsr.deg = getAngles(&jsr);
}

short DualShock3::DeadBand(short js){

	js -= 128;
	//js = (0<js) ? map(js, 0, FROM_MAX_PLUS, 0, TO_MAX) : -map(-js, 0, FROM_MAX_MINUS, 0, TO_MAX);
	if(i_abs(js)<=DEAD_BAND)	js = 0;
	else						js -= (0<js) ? DEAD_BAND : -DEAD_BAND;

	return js;
}

double DualShock3::getRadians(JoyStick *any){

	if( (any->x==0) && (any->y==0) ){
		return -1;
	}else{
		Radians = atan2(any->y, any->x);
		if(0<=Radians)	return Radians;
		else			return Radians+2*M_PI;
	}
}

double DualShock3::getAngles(JoyStick *any){
	if( (any->x==0) && (any->y==0) )	return -1;
	else								return any->rad * (180.0/M_PI);
}

bool DualShock3::pushCount(button *any){

	if(any->press/*_storage*/){
		if(any->flg == 0){
			any->flg = 1;
			return 1;
		}
	}else{
		any->flg = 0;
	}
	return 0;
}

short DualShock3::getPressure(short any){
	//any = (15<any) ? any-16 : 0;
	return (15<any) ? any-16 : 0;
}

void DualShock3::DataReceive(void){

	SCI->read(&rx_buff, 1);

	rx_data[rx_buff&0x0F] = rx_buff;
	data_num++;

	if(data_num==16){
		/*getButton();
		getJoyStick();*/
		data_num = 0;
		Update = 1;
	}
	/*switch(rx_buff&0x0F){
		
		case 0x00:
		data[0] = rx_buff;
		break;
		case 0x01:
		data[1] = rx_buff;
		break;
		case 0x02:
		data[2] = rx_buff;
		break;
		case 0x03:
		data[3] = rx_buff;
		break;
		case 0x04:
		data[5] = rx_buff;
		break;
		case 0x05:
		data[6] = rx_buff;
		break;
		case 0x06:
		data[7] = rx_buff;
		break;
		case 0x07:
		data[8] = rx_buff;
		break;
		case 0x00:
		if((rx_buff&0x08)==0x08)	data[1] = rx_buff;
		else						data[0] = rx_buff;
		break;
	}*/
}

bool DualShock3::is(uint8_t num){
	return !!num;
}

short DualShock3::i_abs(short num){
	return (0<=num) ? num:-num;
}

short DualShock3::map(short num, short from_min, short from_max, short to_min, short to_max){
	return (num - from_min) * (to_max - to_min) / (from_max - from_min) + to_min;
}