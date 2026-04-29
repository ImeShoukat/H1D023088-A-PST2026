# Praktikum Sistem Tertanam - Modul 4B: Pulse Width Module (PWM)
## 4.6.4 Jawaban Pertanyaan Praktikum 
---
#### 1. Jelaskan mengapa LED dapat diatur kecerahannya menggunakan fungsi analogWrite()!
LED dapat diatur kecerahannya menggunakan fungsi analogWrite() karena fungsi ini menghasilkan sinyal Pulse Width Modulation (PWM). PWM bekerja dengan mengatur lebar pulsa (duty cycle) pada sinyal digital.

Meskipun Arduino hanya menghasilkan sinyal digital (HIGH dan LOW), PWM membuat LED menerima daya dalam bentuk pulsa cepat sehingga terlihat seperti mendapatkan tegangan analog. Semakin besar nilai PWM:
- waktu sinyal HIGH lebih lama
- arus yang diterima LED lebih besar
- LED terlihat lebih terang
Sebaliknya, jika nilai PWM kecil, LED akan tampak redup karena durasi sinyal HIGH lebih singkat.

#### 2. Apa hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255)?
Nilai ADC dan PWM memiliki hubungan linier yang dihubungkan melalui proses scaling (mapping).
- ADC memiliki rentang 0–1023 (resolusi 10-bit)
- PWM memiliki rentang 0–255 (resolusi 8-bit)
Karena rentangnya berbeda, nilai ADC perlu dikonversi menjadi PWM menggunakan fungsi map(). Secara sederhana: PWM ≈ ADC / 4. Artinya:
- ADC kecil → PWM kecil → LED redup
- ADC besar → PWM besar → LED terang
Hubungan ini bersifat proporsional sehingga perubahan input analog akan menghasilkan perubahan output yang sebanding.

#### 3. Modifikasilah program berikut agar LED hanya menyala pada rentang kecerahan sedang, yaitu hanya ketika nilai PWM berada pada rentang 50 sampai 200. Jelaskan program pada file README.md.
Kode yang perlu dimodifikasi hanya pada fungsi loop, diubah menjadi sebagai berikut.
```cpp
void loop() {

  nilaiADC = analogRead(potPin);
  pwm = map(nilaiADC, 0, 1023, 0, 255);
  
  //menampangkan pengkondisian setelah mapping adc ke pwm
  if (pwm >= 50 && pwm <= 200) {
    analogWrite(ledPin, pwm); //led hanya aktif pada rentang pwm 50-200
  } else {
    analogWrite(ledPin, 0); // led mati di luar rentang
  }
  ...
}
```
Nilai analog akan dibaca terlebih dahulu dengan fungsi `analogRead()`, yang kemudian dikonversi menjadi nilai PWM 0-255 menggunakan fungsi `map()`. Lalu, digunakan pengkondisian untuk membatasi otput PWM hanya pada rentang 50 hingga 200. Jika nilai PWM berada dalam rentang tersebut, maka LED akan menyala dengan tingkat kecerahan sedang. Diluar rentang tersebut, LED akan dimatikan.

Untuk full kodenya sebagai berikut:
```cpp
#include <Arduino.h> //import library

const int potPin = A0; //deklarasi pin untuk potensiometer
const int ledPin = 9; //deklarasi pin untuk led

int nilaiADC = 0; //inisialisasi variabel untuk menyimpan nilai adc untuk potensiometer
int pwm = 0; //inisialisasi variabel untuk menyimpan nilai pwm untuk led

void setup() {
  pinMode(ledPin, OUTPUT); //membaca led sebagai output
  Serial.begin(9600); //mengaktifkan serial komunikasi
}

void loop() {
  nilaiADC = analogRead(potPin); //membaca nilai potensiometer
  pwm = map(nilaiADC, //mapping nilai adc - pwm
            0, //min adc
            1023, //max adc
            0, //min led
            255); //max led
  if (pwm >= 50 && pwm <= 200) {
    analogWrite(ledPin, pwm); //led hanya aktif pada rentang pwm 50-200
  } else {
    analogWrite(ledPin, 0); // led mati di luar rentang
  }
  Serial.print("ADC: ");
  Serial.print(nilaiADC);

  Serial.print(" | PWM: ");
  Serial.println(pwm);
  delay(50);
}
```
