#include "M5Atom.h"
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

// ポート番号を指定
int s0 = 22;
int s1 = 19;
int s2 = 23;

// アナログ出力
int analog = 33;

// 各変数を宣言
int r0 = 0;
int r1 = 0;
int r2 = 0;

// serial_voltage_byte_sample1
int all_pres[] = {0,0,0,0,0,0,0,0};

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ATOM_BTpress"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(analog, INPUT);
}

void loop() {
  
  for(int i = 0; i < 8; i++){
    chanel(i);
    all_pres[i] = analogRead(analog);
    
    //電圧へ変換
    float pres_vol = (all_pres[i] / 4095.0) * 5.0;
    
    SerialBT.print(i+1);
    SerialBT.print("  ->  "); 
    SerialBT.print(all_pres[i]);    
    SerialBT.print("  "); 
    SerialBT.print("電圧(v)："); 
    SerialBT.println(pres_vol);

    delay( 250 ); 
  }
  
}


void chanel(int j){

    //ある数から指定したビットを読み取る
    r0 = bitRead(j, 0);
    r1 = bitRead(j, 1);
    r2 = bitRead(j, 2);

    // 何番のセンサー読むか指定
    // HIGHかLOWを、指定したピンに出力
    digitalWrite(s0, r0);
    digitalWrite(s1, r1);
    digitalWrite(s2, r2);
}
