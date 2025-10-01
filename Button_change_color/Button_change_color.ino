const int buttonPin = 2;   // 按鈕腳位
const int RledPin = 3;     // 紅色 LED 腳位
const int GledPin = 4;     // 綠色 LED 腳位
const int BledPin = 5;     // 藍色 LED 腳位

// 變數
int buttonState = 0;       // 按鈕狀態
int ledcolor = 0;          // 紀錄目前顏色

void setup() {
  // 初始化 LED 腳位為輸出
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  // 初始化按鈕腳位為輸入
  pinMode(buttonPin, INPUT);
}

void loop() {
  // 讀取按鈕狀態
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    ledcolor = ledcolor + 1;
    delay(100);   // 防止彈跳 (debounce)
  }

  if (ledcolor == 0) {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1) {
    // RED
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 2) {
    // GREEN
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 3) {
    // BLUE
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 4) {
    // YELLOW (紅 + 綠)
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 5) {
    // PURPLE (紅 + 藍)
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 6) {
    // CYAN (綠 + 藍)
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 7) {
    // WHITE (紅 + 綠 + 藍)
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 8) {
    ledcolor = 0;  // 循環回到起點
  }
}
