# Praktikum Sistem Tertanam - Modul 3B: Inter-Integrated Circuit (I2C)
## 3.6.4 Jawaban Pertanyaan Praktikum 
---
#### 1. Jelaskan bagaimana cara kerja komunikasi I2C antara Arduino dan LCD pada rangkaian tersebut!
- Komunikasi I2C menggunakan jalur SDA (serial data) untuk mengirimkan data dan SCL (serial clock) untuk sinkronisasi waktu.
- Dalam rangkaian, arduino berperan sebagai 'master' dan I2C berperan sebagai 'slave' yang memiliki alamat unik
- Arduino akan mengirim snital star memalui bus I2C, lalmu mengirim alamat LCD (misal 0x27)
- Jika alamat cocok, LCD akan merespon
- Arduino mengirim data (text atau karakter)
- LCD menerima dan menampilkan  data

#### 2. Apakah pin potensiometer harus seperti itu? Jelaskan yang terjadi apabila pin kiri dan pin kanan tertukar!
Konfigurasi pin pada potensiometer tidak harus disusun seperti pada percobaan. Namun, terdapat susunan standar yang umum digunakan, yaitu kaki kiri dihubungkan ke GND, kaki kanan ke tegangan 5V, dan kaki tengah ke pin analog sebagai input pembacaan.
- Apabila pin kanan dan kiri ditukar, rangkaian tetap berfungsi dengan baik dan tidak menyebabkan kerusakan pada komponen. Namun, hal ini dapat mempengaruhi arah pembacaan nilai analog. Dalam kondisi normal, ketika potensiometer diputar searah jarum jam, nilai ADC akan meningkat. Sebaliknya, jika kedua pin ditukar, maka ketika diputar ke arah yang sama (searah jarum jam), nilai ADC akan menurun.

#### 3. Modifikasi program dengan menggabungkan antara UART dan I2C
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinPot = A0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int nilai = analogRead(pinPot);

  // Konversi ke Volt
  float volt = nilai * (5.0 / 1023.0);

  // Konversi ke persen
  int persen = map(nilai, 0, 1023, 0, 100);

  // Mapping bar
  int panjangBar = map(nilai, 0, 1023, 0, 16);

  // ===== UART OUTPUT =====
  Serial.print("ADC: ");
  Serial.print(nilai);
  Serial.print(" Volt: ");
  Serial.print(volt, 2);
  Serial.print(" V Persen: ");
  Serial.print(persen);
  Serial.println("%");

  // ===== LCD OUTPUT =====
  lcd.setCursor(0, 0);
  lcd.print("ADC:");
  lcd.print(nilai);
  lcd.print(" ");
  lcd.print(persen);
  lcd.print("% ");

  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    if (i < panjangBar) {
      lcd.print((char)255);
    } else {
      lcd.print(" ");
    }
  }

  delay(200);
}
```

#### 4. Lengkapi table berikut berdasarkan pengamatan pada Serial Monitor
| ADC | Volt (V) | Persen (%) |
|:---:|:--------:|:----------:|
| 1   | 0.00     | 0%         |
| 21  | 0.10     | 2%         |
| 49  | 0.24     | 5%         |
| 74  | 0.36     | 7%         |
| 96  | 0.47     | 9%         |
- Volt = ADC*(5/1023)
- Persen = ADC/1023*100

