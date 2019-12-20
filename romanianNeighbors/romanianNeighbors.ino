#define potentiometerPin A0

typedef struct {
  char *country;
  long int population;
  char *currency;
  char *phoneCode;
  char *internetTLD;
} ROMANIANneighbors;

ROMANIANneighbors bulgaria;
ROMANIANneighbors ukraine;
ROMANIANneighbors serbia;
ROMANIANneighbors moldova;
ROMANIANneighbors hungary;

int incrementState = 0;

void setup() {

  Serial.begin(9600);

  //bulgaria
  bulgaria.country = "Bulgaria";
  bulgaria.population = 7000039;
  bulgaria.currency = "LEV";
  bulgaria.phoneCode = "+359";
  bulgaria.internetTLD = ".bg";

  //ukraine
  ukraine.country = "Ukraine";
  ukraine.population = 42030832;
  ukraine.currency = "UAH";
  ukraine.phoneCode = "+380";
  ukraine.internetTLD = ".ua";

  //serbia
  serbia.country = "Serbia";
  serbia.population = 6963764;
  serbia.currency = "RSD";
  serbia.phoneCode = "+381";
  serbia.internetTLD = ".rs";

  //moldova
  moldova.country = "Moldova";
  moldova.population = 2681735;
  moldova.currency = "LEU";
  moldova.phoneCode = "+373";
  moldova.internetTLD = ".md";

  //hungary
  hungary.country = "Hungary";
  hungary.population = 9772756;
  hungary.currency = "HUF";
  hungary.phoneCode = "+36";
  hungary.internetTLD = ".hu";
}

void loop() {
  int iterativeValue = 0, oldIterativeValue = 0;

  int potentiometerValue = analogRead(potentiometerPin);
  potentiometerValue = map(potentiometerValue, 0 , 1023, 1, 6);

  //print the output after each 5s
  if (incrementState % 5000 == 0) {
    if (potentiometerValue == 1) {
      Serial.print("Neighbor number: ");
      Serial.println(potentiometerValue);
      Serial.println("-----");

      Serial.print("Country: ");
      Serial.println(bulgaria.country);

      Serial.print("Population: ");
      Serial.println(bulgaria.population);

      Serial.print("Currency: ");
      Serial.println(bulgaria.currency);

      Serial.print("Phone CODE: ");
      Serial.println(bulgaria.phoneCode);

      Serial.print("Internet TLD: ");
      Serial.println(bulgaria.internetTLD);
      Serial.println("-----");

    }

    if (potentiometerValue == 2) {
      Serial.print("Neighbor number: ");
      Serial.println(potentiometerValue);
      Serial.println("-----");

      Serial.print("Country: ");
      Serial.println(ukraine.country);

      Serial.print("Population: ");
      Serial.println(ukraine.population);

      Serial.print("Currency: ");
      Serial.println(ukraine.currency);

      Serial.print("Phone CODE: ");
      Serial.println(ukraine.phoneCode);

      Serial.print("Internet TLD: ");
      Serial.println(ukraine.internetTLD);
      Serial.println("-----");

    }

    if (potentiometerValue == 3) {
      Serial.print("Neighbor number: ");
      Serial.println(potentiometerValue);
      Serial.println("-----");

      Serial.print("Country: ");
      Serial.println(serbia.country);

      Serial.print("Population: ");
      Serial.println(serbia.population);

      Serial.print("Currency: ");
      Serial.println(serbia.currency);

      Serial.print("Phone CODE: ");
      Serial.println(serbia.phoneCode);

      Serial.print("Internet TLD: ");
      Serial.println(serbia.internetTLD);
      Serial.println("-----");

    }

    if (potentiometerValue == 4) {
      Serial.print("Neighbor number: ");
      Serial.println(potentiometerValue);
      Serial.println("-----");

      Serial.print("Country: ");
      Serial.println(moldova.country);

      Serial.print("Population: ");
      Serial.println(moldova.population);

      Serial.print("Currency: ");
      Serial.println(moldova.currency);

      Serial.print("Phone CODE: ");
      Serial.println(moldova.phoneCode);

      Serial.print("Internet TLD: ");
      Serial.println(moldova.internetTLD);
      Serial.println("-----");

    }

    if (potentiometerValue == 5) {
      Serial.print("Neighbor number: ");
      Serial.println(potentiometerValue);
      Serial.println("-----");

      Serial.print("Country: ");
      Serial.println(hungary.country);

      Serial.print("Population: ");
      Serial.println(hungary.population);

      Serial.print("Currency: ");
      Serial.println(hungary.currency);

      Serial.print("Phone CODE: ");
      Serial.println(hungary.phoneCode);

      Serial.print("Internet TLD: ");
      Serial.println(hungary.internetTLD);
      Serial.println("-----");

    }
  }

  //increment with 1s
  incrementState += 1000;

  //refreshing after 10s
  if (incrementState == 10000) {
    incrementState = 0;
  }

  delay(1000);

}
