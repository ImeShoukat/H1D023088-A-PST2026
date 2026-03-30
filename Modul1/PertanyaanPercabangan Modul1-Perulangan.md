# Praktikum Sistem Tertanam - Modul 1 Perulangan
## Jawaban Pertanyaan Praktikum 
### 1. Gambarkan rangkaian schematic 5 LED running yang digunakan pada percobaan!
Rangkaian tediri dari 4 LED yang dihubungkan ke pin digital Arduino (6-9). Setiap katoda anoda LED dihubungkan secara seri tanpa resistor pada breadboard yang kemudian dihubungkan ke pin 6-9 menggunakan kabel jumper. Katoda LED kemudian dihubungkan ke GND.
Konfigurasi rangkaian sebagai berikut:
| No | Pin | Keterangan        |
|----|-----|-------------------|
| 1  | 9   | LED hijau 1       |
| 2  | 8   | LED hijau 2       |
| 3  | 7   | LED kuning        |
| 3  | 6   | LED merah         |

Gambaran rangkaian bisa dilihat pada gambar berikut:
![Rangkaian LED](https://drive.google.com/file/d/1qDMhanZHEChQucn1PLge6qjf0LOQpCGn/view?usp=sharing)

### 2. Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan!
Efek LED berjalan dari kiri ke kanan dibuat menggunakan struktur perulangan for dengan pola kenaikan nilai (increment). Program dimulai dari pin dengan nomor terkecil (misalnya pin 6) hingga pin terbesar (misalnya pin 9).
Contoh perulangan yang digunakan:
```cpp
for (int ledPin = 6; ledPin < 10; ledPin++){
  digitalWrite(ledPin, HIGH); 
  delay(timer); 
  digitalWrite(ledPin, LOW);
}
```
Pada setiap iterasi, LED pada pin yang sedang aktif akan dinyalakan menggunakan `digitalWrite(ledPin, HIGH)`, kemudian diberikan jeda waktu menggunakan `delay(timer)`, lalu dimatikan kembali dengan `digitalWrite(ledPin, LOW)` sebelum berpindah ke LED berikutnya.
Proses ini dilakukan secara berurutan dari pin terkecil ke pin terbesar sehingga menghasilkan efek visual LED yang tampak bergerak dari kiri ke kanan.
### 3. Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri!
Efek LED kembali dari kanan ke kiri dibuat menggunakan struktur perulangan for dengan pola penurunan nilai (decrement), yaitu dari pin terbesar ke pin terkecil.
```cpp
for (int ledPin = 9; ledPin >= 6; ledPin--) { 
  digitalWrite(ledPin, HIGH); 
  delay(timer); 
  digitalWrite(ledPin, LOW); 
} 
```
Perulangan dimulai dari pin terbesar (pin 9) kemudian berkurang hingga pin terkecil (pin 6). Pada setiap iterasi, LED dinyalakan menggunakan `digitalWrite(ledPin, HIGH)`, kemudian diberikan jeda waktu menggunakan `delay(timer)`, lalu dimatikan kembali dengan `digitalWrite(ledPin, LOW)`.

Karena urutan pin berjalan dari besar ke kecil, maka LED akan menyala secara berurutan dari kanan ke kiri. Hal ini menghasilkan efek visual LED yang tampak kembali ke arah semula.
### 4. Buatkan program agar LED menyala tiga LED kanan dan tiga LED kiri secara bergantiandan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
**Kode Program**
```cpp
int timer = 200; // waktu delay (kecepatan perpindahan LED)
void setup() {
  // Mengatur pin 6 sampai 11 sebagai output
  for (int ledPin = 6; ledPin <= 11; ledPin++) {
    pinMode(ledPin, OUTPUT);
  }
}
void loop() {
  // Menyalakan LED kiri (pin 6, 7, 8)
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);

  // Mematikan LED kanan (pin 9, 10, 11)
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  delay(timer); // jeda

  // Menyalakan LED kanan (pin 9, 10, 11)
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);

  // Mematikan LED kiri (pin 6, 7, 8)
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(timer); // jeda
}
```
#### Penjelasan kode per baris
##### - menentukan waktu delay
```cpp
int timer = 200;
```
Menentukan nilai delay sebesar 200 ms untuk mengatur kecepatan pergantian nyala LED.
##### - Inisiasi awal program
```cpp
void setup () {...}
```
Fungsi yang dijalankan sekali saat Arduino pertama kali dinyalakan.
##### - Inisialisai Pin
```cpp
for (int ledPin = 6; ledPin <= 11; ledPin++) {...}
```
Pin LED (pin 6 sampai 11) diatur dengan perulangan agar tersusun secara otomatis.
##### - Konfigurasi pin sebagai output
```cpp
pinMode(ledPin, OUTPUT);
```
Mengatur setiap pin LED sebagai output agar dapat mengirim sinyal listrik.
##### - Fungsi perulangan
```cpp
void loop (){...}
```
Fungsi utama yang dijalankan secara terus-menerus selama Arduino aktif.
##### - Menyalakan LED kiri
```cpp
digitalWrite(6, HIGH); digitalWrite(7, HIGH); digitalWrite(8, HIGH);
```
Menyalakan tiga LED bagian kiri secara bersamaan.
##### - Mematikan LED kanan 
```cpp
digitalWrite(9, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
```
Mematikan tiga LED bagian kanan.
##### - Jeda waktu
```cpp
delay(timer);
```
Memberi jeda waktu
##### - Menyalakan LED kanan 
```cpp
digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(11, HIGH);
```
Menyalakan tiga LED bagian kanan secara bersamaan
##### - Menyalakan LED Kiri
```cpp
digitalWrite(6, LOW); digitalWrite(7, LOW); digitalWrite(8, LOW);
```
Mematikan tiga LED bagian kiri.
##### - Jeda waktu
```cpp
delay(timer);
```
Memberikan jeda waktu agar efek pergantian LED terlihat jelas.

### Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa struktur perulangan (`for`) pada Arduino dapat digunakan untuk mengontrol nyala LED secara berurutan sehingga menghasilkan efek running LED dari kiri ke kanan maupun sebaliknya. Selain itu, penggunaan logika output digital (`HIGH` dan `LOW`) memungkinkan pengaturan pola nyala LED, seperti efek bergantian antara sisi kiri dan kanan.

Variabel delay berperan penting dalam mengatur kecepatan perpindahan nyala LED, sehingga dapat menghasilkan efek visual yang jelas. Dengan demikian, kombinasi perulangan, kontrol output, dan delay dapat digunakan untuk menciptakan berbagai pola LED yang dinamis sesuai kebutuhan.
