// ポート番号を指定

int s0 = 2;
int s1 = 3;
int s2 = 4;


// 各変数を宣言

int r0 = 0;
int r1 = 0;
int r2 = 0;


// serial_voltage_byte_sample1

int all_pres[] = {0,0,0,0,0,0,0,0};


void setup() {
  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  
  Serial.begin( 9600 );
}

void loop() {

  for(int i = 0; i < 8; i++){

    chanel(i);
    all_pres[i] = analogRead(A0);
    
//  電圧へ変換
    float pres_vol = (all_pres[i] / 1024.0) * 5.0;
    
    Serial.print(i+1);
    Serial.print("  ->  "); 
    Serial.print(all_pres[i]);    
    Serial.print("  "); 
    Serial.print("電圧(v)："); 
    Serial.println(pres_vol);

    delay( 200 ); 
  }
}


void chanel(int j){

    //ある数から指定したビットを読み取る
    r0 = bitRead(j, 0);
    r1 = bitRead(j, 1);
    r2 = bitRead(j, 2);


    // 何番のセンサー読むか指定
    // HIGHかLOWを、指定したピンに出力
    digitalWrite(2, r0);
    digitalWrite(3, r1);
    digitalWrite(4, r2);
}
