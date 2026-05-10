# Praktikum Sistem Tertanam - Modul 4A: Analog to Digital Converter (ADC)
## 4.5.4 Jawaban Pertanyaan Praktikum 
---
#### 1. Apa fungsi perintah `analogRead()` pada rangkaian praktikum ini?
Perintah `analogRead()` berfungsi untuk membaca nilai tegangan analog dari potensiometer yang terhubung ke pin analog Arduino. Nilai tegangan tersebut kemudian dikonversi menjadi data digital oleh ADC dengan resolusi 10-bit, sehingga menghasilkan nilai dalam rentang 0 hingga 1023. Pada percobaan 1, `analogRead()` digunakan untuk mengetahui posisi putaran potensiometer.

#### 2. Mengapa diperlukan fungsi map() dalam program tersebut?
Fungsi map() digunakan untuk mengonversi nilai dari satu rentang ke rentang lain secara linier. Dalam percobaan 1, nilai ADC yang berada pada rentang 0–1023 tidak dapat langsung digunakan untuk mengontrol perangkat output seperti servo. Oleh karena itu, diperlukan fungsi map() untuk mengubah nilai ADC (0-1023) menjadi sudut servo (0-180 derajat).
 

#### 3. Modifikasi program berikut agar servo hanya bergerak dalam rentang 30° hingga 150°, meskipun potensiometer tetap memiliki rentang ADC 0–1023. Jelaskan program pada file R EADME.md
Bagian yang cukup dimodifikasi adalah pada bagian mapping di fungsi loop, menjadi:
```cpp
void loop() {
  val = analogRead(potensioPin); 
  pos = map(val,
             0, // nilai minimun adc
             1023, // nilai maksimum adc
             30, // nilai minimum sudut servo yang diminta, yaitu 30 derajat
             150); // nilai maksimum sudut servo yang diminta, yaitu 150 derajat
  ...
}
```
Nilai analog dibaca menggunakan fungsi `analogRead()` dalam rentang 0-1023. Nilai tersebut dikonversi menggunakan fungsi `map()` menjadi rentang sudut 30 hingga 150 derajat. Hal ini dilakukan untuk membatasi rentang sudut servo seperti yang diminta.

Sehingga kode lengkap menjadi seperti berikut:
```cpp
#include <Servo.h> //import library
Servo myservo; // deklarasi objek 

const int potensioPin = A0; //deklarasi pin untuk potensiometer
const int servoPin = 9;  // deklarasi pin untuk servo

int pos = 0; // inisialisasi variabel untuk menyimpan sudut potensiometer
int val = 0; // inisialisasi variabel untuk menyimpan nilai adc

void setup() {
  myservo.attach(servoPin);  // menghubungkan objek servo ke pin 9
  Serial.begin(9600); // mengaktifkan komunikasi serial
}

void loop() {
  val = analogRead(potensioPin); //membaca nilai analog dari potensiometer
  pos = map(val, //mengubah nilai adc menjadi sudut servo
             0, //nilai minimum ADC
             1023, //nilai maksimum ADC
             30, //sudut minimum servo
             150); //sudut maksimum servo
  myservo.write(pos); // menggerakan sudut servo sesuai hasil mapping dari potensiometer
  Serial.print("ADC Potensio: "); // menampilkan text ke serial monitor
  Serial.print(val); //menampilkan nilai adc
  Serial.print(" | Sudut Servo: "); //menampilkan text tanbahan
  Serial.println(pos); //menampilkan besar sudut servo

  delay(15); //jeda pergerakan servo setiap diputar sebesar 15ms
}
```

