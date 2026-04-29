# Praktikum Sistem Tertanam - Modul 3A: Komunikasi Serial (UART)
## 3.5.4 Jawaban Pertanyaan Praktikum 
---
#### 1. Jelaskan proses dari input keyboard hingga LED menyala/mati!
- Ketika user mengetikan `'1'` atau `'0'` pada serial monitor, data akan dikirimkan ke Arduino melalui komunikasi serial UART melalui kabel USB.
- Arduino kemudian menerima data tersebut dan menyimpannya sementara di dalam buffer serial.
- Program Arduino akan terus mengecek apakah ada data yang masuk menggunakan fungsi `Serial.available()`. Jika ada data, maka Arduino akan membaca data tersebut menggunakan `Serial.read()`.
- Data yang diterima akan dibandingkan. Apabila data yang masuk bernilai `'1'`, maka Arduino akan memberi sinyal HIGH ke pin LED. Namun, apabila data yang diterima bernilai `'0'`, maka Arduino akan memberikan sinyal LOW ke pin LED sehingga LED mati.

#### 2. Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika baris tersebut dihilangkan?
Fungsi `Serial.available()` digunakan untuk mengecek apakah terdapat data yang tersedia di buffer serial sebelum dilakukan pembacaan dengan `Serial.read()`. `Serial.read()` hanya dapat membaca data jika data memang tersedia. Sehingga apabila tidak ada data, tetapi tetap dilakukan pembacaan, maka akan menghasilkan nilai yang tidak valid.
<br>
Jika baris `Serial.available()` dihilangkan, program akan terus membaca data meskipun tidak ada input. Akibatnya data yang dibaca bisa tidak valid, program dapat memberikan respon yang tidak sesuai, serta serial monitor bisa menampilkan pesan error secara terus-menerus.  

#### 3. Modifikasi program agar LED berkedip (blink) ketika menerima input '2' dengan kondisi jika ‘2’ aktif maka LED akan terus berkedip sampai perintah selanjutnya diberikan dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
```cpp
const int PIN_LED = 12; // menentukan pin digital yang digunakan untuk LED, which mean itu pin 12
bool blinking = false; // variabel untuk menyimpan status apakah LED dalam mode berkedip
unsigned long previousMillis = 0; // menyimpan waktu terakhir LED berubah
const long interval = 500; // menentukan interval waktu kedip (500ms)
bool ledState = LOW; //menyimpan kondis LED (nyala atau mati)

void setup() { 
  Serial.begin(9600); //memulai komunikasi serial
  Serial.println("Ketik '1' ON, '0' OFF, '2' BLINK"); 
  pinMode(PIN_LED, OUTPUT); // mengatur pin LED sebagai output
}

void loop() {
  if (Serial.available() > 0) { // mengecek apa ada data yang masuk
    char data = Serial.read(); //membaca data dari serial monitor

    if (data == '1') { //jika input user 1 = led nyala, blink dimatikan
      blinking = false;
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED ON");
    }
    else if (data == '0') { //jika input user 0 = LED mati, blink dimatikan 
      blinking = false;
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED OFF");
    }
    else if (data == '2') {  // jika input user 2 = blink diaktifkan
      blinking = true;
      Serial.println("LED BLINK");
    }
  }

  if (blinking) { // mengecek apakah mode blinkling aktif atau tidak
    unsigned long currentMillis = millis(); // mengambil waktu saat ini sejak Arduino menyala (dalam ms)

    if (currentMillis - previousMillis >= interval) { // menghitung selisih waktu sekarang dengan waktu terakhir LED berubah
      previousMillis = currentMillis; // update waktu terakhir LED berubah
      ledState = !ledState; // membalik kondisi LED agar berkedip
      digitalWrite(PIN_LED, ledState); // mengirim sinyal LED sesuai kondisi terbaru
    }
  }
}
```

#### 4. Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap sistem
Fungsi `delay()` bersifat blocking. Artinya selama delay berlangsung, Arduino tidak dapat menjalankan proses lain termasuk membaca input dari serial monitor. Hal ini menyebabkan sistem menjadi lambat dan tidak responsif. Sedangkan `millis()` bersifat non-blocking sehingga Arduino tetap dapat menjalankan proses blinking LED. 
Pengaruhnya terhadap sistem:
- `delay()` membuat sistem tidak resposif terhadap input baru
- `millis ()` membuat sistem responsif dan mampu menangani beberapa proses sekaligus (dapat multitasking sederhana)
