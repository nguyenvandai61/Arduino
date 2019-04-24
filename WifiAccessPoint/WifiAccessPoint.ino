#include <ESP8266WiFi.h>        // Include the Wi-Fi library

#include <SocketIOClient.h>

const int ledPin = D1;

SocketIOClient client;
const char *ssid = "ESP8266 Access Point"; // The name of the Wi-Fi network that will be created
const char *password = "12345678";   // The password required to connect to it, leave blank for an open network


char host[] = "192.168.4.2";  //Địa chỉ IP dịch vụ, hãy thay đổi nó theo địa chỉ IP Socket server của bạn.
int port = 8888;                  //Cổng dịch vụ socket server do chúng ta tạo!
 
//từ khóa extern: dùng để #include các biến toàn cục ở một số thư viện khác. Trong thư viện SocketIOClient có hai biến toàn cục
// mà chúng ta cần quan tâm đó là
// RID: Tên hàm (tên sự kiện
// Rfull: Danh sách biến (được đóng gói lại là chuối JSON)
extern String RID;
extern String Rfull;


//Một số biến dùng cho việc tạo một task
unsigned long previousMillis = 0;
long interval = 2000;


void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin, OUTPUT);
  Serial.println('\n');

  WiFi.softAP(ssid, password);             // Start the access point
  Serial.print("Access Point \"");
  Serial.print(ssid);
  Serial.println("\" started");

  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());         // Send the IP address of the ESP8266 to the computer
  if (!client.connect(host, port)) {
    Serial.println(F("Ket noi den socket server that bai!"));
    return;
  }

  //Khi đã kết nối thành công
  if (client.connected()) {
    //Thì gửi sự kiện ("connection") đến Socket server ahihi.
    client.send("connection", "message", "Connected !!!!");
  }
}

void loop()
{
  //tạo một task cứ sau "interval" giây thì chạy lệnh:
  if (millis() - previousMillis > interval) {
    //lệnh:
    previousMillis = millis();

    //gửi sự kiện "atime" là một JSON chứa tham số message có nội dung là Time please?
    client.send("OnOrOff", "message", "Ready!");
  }

  //Khi bắt được bất kỳ sự kiện nào thì chúng ta có hai tham số:
  //  +RID: Tên sự kiện
  //  +RFull: Danh sách tham số được nén thành chuỗi JSON!
  if (client.monitor()) {
    Serial.println(RID);
    Serial.println(Rfull);


    if (Rfull == "1") {
      digitalWrite(ledPin, HIGH);
      client.send("TurnedOn", "message", "Turned on");
    }
    if (Rfull == "0") {
      digitalWrite(ledPin, LOW);
      client.send("TurnedOff", "message", "Turned off");
    }
  }

  //Kết nối lại!
  if (!client.connected()) {
    client.reconnect(host, port);
  }
}
