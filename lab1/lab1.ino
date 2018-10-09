String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                    ".--", "-..-", "-.--", "--.."};
                    
String numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

String testString = "SOS 5";


int led = 13;
int timeUnit = 100;
int elementGap = timeUnit;
int shortGap = timeUnit * 3;
int mediumGap = timeUnit * 7;

void setup() {
  // put your setup code here, to run once:
  pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay (timeUnit * 30);
  for (int i = 0; i < testString.length(); i++)
  {
    char c = testString.charAt(i);
    c = toLowerCase(c);

    if (c == ' ')
      delay (mediumGap);
    else if (c >= '0' && c <= '9')
      Light (numbers[c - '0']);
    else
      Light (letters[c - 'a']);
  }
}

void Light (String code)
{
  for (int i = 0; i < code.length(); i++)
  {
    if (i != 0)
      delay (elementGap);
    
    digitalWrite (led, HIGH);
    if (code.charAt(i) == '.')
      delay (timeUnit);
    else
      delay (timeUnit * 3);

    digitalWrite (led, LOW);
  }
  delay (shortGap);
}
