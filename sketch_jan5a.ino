//   #define RXD2 16
//   #define TXD2 17



// void receive_light_data() {
//   for(;;){
//     if (Serial2.available()) {
//     String receivedData = Serial2.readString();
//     Serial.print("Received data from UART2: ");
//     // Serial.println(receivedData);
//     int lightValue = receivedData.toInt();
//     Serial.println(lightValue);

//     delay(200);
//   }
//   }
// }

//   void setup() {
//     // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
//     Serial.begin(115200);
//     //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
//     Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
//     Serial.println("Serial Txd is on pin: "+String(TX));
//     Serial.println("Serial Rxd is on pin: "+String(RX));
//     receive_light_data();
//   }

//   void loop() { 
//     // while (Serial2.available()) {
//     //   // Serial.print(char(Serial2.read()));
//     //   char receivedData = Serial2.read();
//     //   int lightValue = receivedData.toInt();
//     //   Serial.print(lightValue);
//     // }
//     // receive_light_data();
//   }

#include <ArduinoJson.h>
// #include <FirebaseESP32.h>
#include<ESP32Firebase.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include <Arduino.h>
#include <DHT.h>
// #include <IOXhop_FirebaseESP32.h>    


#define DHTPIN 26    
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
#define RXD2 16
#define TXD2 17


#define DATABASE_URL "https://project3-a87e0-default-rtdb.asia-southeast1.firebasedatabase.app/"
// #define API_KEY "AIzaSyCBRn4_maYwJ8ZkGdZ-20q22Pj9WIpBOi0"
// #define FIREBASE_authorization_key "wx6CuOQ5ycSLqaBhJ1CyHTVAmjtsDxKtoJCiAmBV"
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;
const char *ssid = "vivo 1820";
const char *password = "12345678";

Firebase firebase(DATABASE_URL);
int lightValue = 0;
void receive_light_data(void*) {
  for(;;){
  if (Serial2.available()) {
    String receivedData = Serial2.readStringUntil('\n'); // Đọc dữ liệu cho đến khi gặp ký tự xuống dòng
    receivedData.trim(); // Xóa các khoảng trắng thừa
    Serial.print("Received data from UART2: ");
    Serial.println(receivedData);
    lightValue = receivedData.toInt();
    if (lightValue != 0) {
      Serial.println(lightValue);
    }
    delay(200);
  }
  }
}
  String myhum;
  String mytemp;
  String mylight;
void temp_humi_gglefire_data(void* parameter) {
  for(;;){
  // FirebaseJson json;
  float h = dht.readHumidity();
  delay(2000);
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    continue;
  }
  char buff[10];
  // String myhum;
  // String mytemp;
  // String mylight;
  Serial.print("Nhiet do: ");
  Serial.print(t);
  Serial.print("*C  ");
  Serial.print("Do am: ");
  Serial.print(h);
  Serial.println("%  ");
  myhum = dtostrf(h,3,2,buff);
  mytemp = dtostrf(t,3,2,buff);
  mylight = dtostrf(lightValue,3,2,buff);
  delay(100); 
  // json.set("/hum", myhum);
  // json.set("/temp", mytemp);
  // json.set("/light", mylight);
  // Firebase.updateNode(fbdo ,"/Sensor",json);
  // firebase.setString("Sensor/hum", myhum);
  // firebase.setString("Sensor/temp", mytemp);
  // firebase.setString("Sensor/light", mylight);
  delay(200);
  }
  
}


void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial Txd is on pin: " + String(TXD2));
  Serial.println("Serial Rxd is on pin: " + String(RXD2));
  WiFi.begin(ssid, password);
  Serial.print("Dang ket noi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  // config.api_key = API_KEY;
  // config.database_url = DATABASE_URL;
  // // Firebase.begin(&config, &auth);
  // // auth.user.email = "truonglocnguyenkhanh@gmail.com";  // Thêm thông tin đăng nhập email của bạn vào đây
  // // auth.user.password = "Thegioinaylasao2002";  // Thêm thông tin mật khẩu của bạn vào đây
  
  // Firebase.begin(&config, &auth);
  // Firebase.reconnectWiFi(true);

  // Firebase.begin(DATABASE_URL,FIREBASE_authorization_key);
  // firebase.setString("Sensor/hum", myhum);
  // firebase.setString("Sensor/temp", mytemp);
  // firebase.setString("Sensor/light", mylight);
  xTaskCreate(receive_light_data, "receive_light_data", 1024*2,NULL,1,NULL);
  xTaskCreate(temp_humi_gglefire_data, "temp_humi_gglefire_data", 1024*2,NULL,1,NULL);
  // Firebase.begin(DATABASE_URL, FIREBASE_authorization_key);   

}

void loop() {
  // receive_light_data();
  // temp_humi_gglefire_data();
  firebase.setString("Sensor/hum", myhum);
  firebase.setString("Sensor/temp", mytemp);
  firebase.setString("Sensor/light", mylight);
  }