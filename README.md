# kunstspeeltuin
GitHub Team 4 Diya Jawalapersad en Astrid Prins

De Moodlamp en de Kijkdoos zijn interactieve installatie onderdelen van de installatie voor de beroepsopdracht (BO) en examen keuze onderdeel Special Input Output van module 6 jaar 2 2023/2024 van de Software Development opleiding aan het Mediacollege Amsterdam. 
De opdrachtgever van de BO opdracht is het museum Het Upside Down. Er wordt een expo gegeven van alle installaties op 30 januari 2024.
De installatie wordt in samenwerking gemaakt met de opleidingen Ruimtelijke Vormgever, Software Development en E-commerce Design.
Onderdelen van de installatie gemaakt door de Software Developers
Tevens is het ook een Examenonderdeel Special Input Output.

## Webcam
### toelichting en gebruik
De webcam is gemaakt met een face recognition api. Als de api de expressie 'happy' detecteerd wordt er na 2 seconden een foto gemaakt van het canvas en wordt de afbeelding gedownload.

face-api: https://justadudewhohacks.github.io/face-api.js/docs/index.html

## Kijkdoos door Astrid Prins 
### Gebruik
De kijkdoos wordt gebruikt door je hoofd door een gat van een doos te steken, vervolgens wordt er een laser onderbroken die de ervaring start. Deze bestaat uit LED lampjes en servo motoren.

De achterwand bestaat uit gekleurde vlakken die standaard zijn opgelicht door LED lampjes. Aan beide kanten van de muur zijn gekleurde vlakken aanwezig die willekeurig bij de start van de ervaring naar de gebruiker toe worden gedraaid. Ook zijn aan beide kanten van de muur gekleurde LED lampjes aanwezig die aangaan bij de start van de ervaring.

### Code
Het begin van de code bestaat uit het toewijzen van de laser, LDR, servo's en LEDS aan pins en het vormen van arrays.

In de setup worden input en output toegewezen aan de laser, LDR, servo's en  LEDS. 
Standaard staan de LED aan de achterwand aan.

In de loop wordt gekeken of de laser wordt onderbroken, vervolgens wordt de stand van de kijkdoos aangegeven als die uit staat (dus als de laser connect met de ldr). De servo's staan in hun begin stand en de LEDS aan de muur staan uit.

Daarna in de code staat de wat er gebeurt als de laser onderbroken is, er worden 6x een willekeurig nummer gegeneerd tussen de 0 en 14. Als de nummers overeen komen met het getal van de servo wordt de servo geactiveerd. Dit veroorzaakt dat niet alle servo's aan staan maar per keer een paar.
Ook worden de LEDS aan de muren aangezet.