const int soilMoisturePin = A0; // Pin analog untuk sensor kelembaban tanah

void setup() {
  Serial.begin(9600); // Memulai komunikasi serial dengan baud rate 9600
}

void loop() {
  // int soilMoistureValue = analogRead(soilMoisturePin); // Membaca nilai analog dari sensor kelembaban tanah
  float soilMoisturePercentage;
  int soilMoistureValue;
  soilMoistureValue = analogRead(soilMoisturePin);
  soilMoisturePercentage = ( 82.41 - ( (soilMoistureValue/1023.00) * 100 ) );//kalibrasi sensor untuk kelembapan tanah
  // Konversi nilai analog ke persentase kelembaban tanah
  // float soilMoisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);

  // Menggunakan rumus kalibrasi untuk mengestimasi EC berdasarkan kelembaban tanah
  float a = 2.5; // Koefisien kemiringan dari hasil regresi linier
  float b = 50.0; // Intersep dari hasil regresi linier
  float estimatedEC = a * soilMoisturePercentage + b;

  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisturePercentage);
  Serial.print("%, Estimated EC: ");
  Serial.print(estimatedEC);
  Serial.println(" uS/cm");

  delay(1000); // Tunggu 1 detik sebelum pembacaan berikutnya
}
