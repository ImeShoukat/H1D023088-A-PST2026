# Jawaban Pertanyaan Praktikum
## Modul Percabangan
### 1. Pada kondisi apa program masuk ke blok `if`?
Program masuk ke blok `if` ketika nilai:
```
timeDelay<=100
```
Kondisi inin menunjukan bahwa LED telah mencapai kecepatan maksimum, sehingga program melakukan reset
### 2. Pada kondisi apa program masuk ke blok `else`?
Program masuk ke blok `ēlse` ketika:
```
timeDelay > 100
```
Pada kondisi ini, LED masih dalam keadaan lambat atau sedang, sehingga delay akan terus dikurangi untuk mempercepat kedipan LED.
### 3. Apa fungsi dari perintah `delay(timeDelay)`?
Perintah `delay(timeDelay)` berfungsi untuk memberikan jeda waktu sesuai nilai `timeDelay`. Nilai ini menentukan cepat atau lambatnya LED berkedip, di mana semakin besar nilainya maka LED semakin lambat, dan semakin kecil nilainya maka LED semakin cepat
### 4. Program jika diubah alurnya menjadi mati → lambat → cepat → sedang -> mati
Apabila program yang awal alurnya mati-> lambat -> cepat -> riset -> mati, diubah menjadi mati → lambat → cepat → sedang -> mati
**Kode Program**
```
const int ledPin = 11;     
int timeDelay = 1000;      

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  digitalWrite(ledPin, HIGH);
  delay(timeDelay);

  digitalWrite(ledPin, LOW);
  delay(timeDelay);

  if (timeDelay > 200) {
    timeDelay -= 200;   // dari lambat → cepat
  } 
  else if (timeDelay > 100) {
    timeDelay = 500;    // dari cepat → sedang
  } 
  else {
    digitalWrite(ledPin, LOW);
    delay(3000);        // kondisi mati
    timeDelay = 1000;   // kembali ke awal
  }
}
```
Dari kode tersebut, dapat dilihat program dimulai dengan delay sebesar 1000 (1s) sehingga LED berkedip lambat. Kemudian delay dikurang secara bertahab sehingga LED menjadi lebih cepat. Setelah mencapai kondisi tertentu, kecepatan diubah menjadi sedang sebelum akhirnya LED dimatikan sementara.
