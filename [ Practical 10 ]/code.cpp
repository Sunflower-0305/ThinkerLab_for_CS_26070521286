int soilsensor = 0;

void setup()

pinMode (A5, INPUT);


Serial.begin(9600);


pinMode (11, OUTPUT);


pinMode (10, OUTPUT);


pinMode (2, OUTPUT);
}

void loop()
soilsensor = analogRead (A5); Serial.println(soilsensor);


if (soilsensor<400) (


}else{


digitalWrite (11, HIGH);


digitalWrite (12, LOW);


digitalWrite (2, HIGH);


digitalWrite (11, LOW); digitalWrite (12, HIGH); digitalWrite (2, LOW);


}


delay (10);


}
