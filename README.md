# Murmel-Simulation (Berufsschulprojekt FIAE 2025)

Dieses Repository enthält das Unreal Engine 5 Projekt für eine Murmel-Simulation, entwickelt im Rahmen der Projektarbeit für Fachinformatiker Anwendungsentwicklung an der Berufsschule Technik in Rostock.

## 📝 Projektbeschreibung

Die Anwendung ist eine **zeitabhängige Simulation** einer Murmelbahn. Der Benutzer kann diverse physikalische Parameter von Murmeln konfigurieren und ein Rennen mit mehreren KI-gesteuerten Murmeln auf einer prozedural generierten Strecke starten. Die Anwendung dient dazu, die Auswirkungen verschiedener Eingabeparameter und Zufallsfaktoren auf das Ergebnis eines physikalischen Systems visuell darzustellen und auszuwerten.

Das Projekt wurde entwickelt, um alle funktionalen und nicht-funktionalen Anforderungen des Projektauftrags zu erfüllen.

## ✨ Features

Das Projekt implementiert folgende, im Projektauftrag geforderte Features:

* **5 Eingabeparameter:** Der Benutzer kann vor jeder Simulation mindestens fünf Parameter (z.B. Masse, Reibung, Elastizität) der Murmel einstellen.
* **3 Zufallsverteilungen:** Die Simulation nutzt mindestens drei verschiedene Zufallsverteilungen, um unvorhersehbare, aber realistische Ereignisse zu modellieren.
* **Variable Simulationsgeschwindigkeit:** Die Abspielgeschwindigkeit der Simulation kann in mindestens 3 Stufen (z.B. 0.5x, 1.0x, 2.0x) eingestellt werden.
* **Visuelle Darstellung & Auswertung:** Die Simulation wird in 3D visualisiert. Nach Abschluss eines Rennens werden die Ergebnisse (Zeit, Platzierung) in einer Übersicht dargestellt.
* **GUI & User Experience:** Die Anwendung verfügt über eine grafische Benutzeroberfläche, die nach den Interaktionsprinzipien der ISO 9241-110 gestaltet wurde.

# Anforderungsdokumentation (IHK-Projekt)

## 1. Funktionale Anforderungen

#### Zeitabhängige Simulation
* Die Kernanwendung misst die Zeit, die Murmeln für eine Strecke benötigen. Diese Zeitdaten bilden die Grundlage für die spätere Auswertung und den Vergleich der Simulationsläufe.

#### Mindestens 3 Zufallswerte mit verschiedenen Verteilungen
* **Gleichverteilung:** Wird für die prozedurale Generierung der Rennstrecke verwendet, indem zufällig und mit gleicher Wahrscheinlichkeit aus einem Pool von vordefinierten Streckenteilen ausgewählt wird.
* **Normalverteilung:** Dient der Simulation von Umwelteinflüssen wie "Windstößen". Eine permanent wirkende, normalverteilte Zufallskraft beeinflusst die Murmeln, wobei die meisten Kraftstöße nahe Null liegen. Benötigt auch eine visuelle Darstellung.
* **Exponentialverteilung:** Steuert die Zeit zwischen den Aktivierungen von dynamischen Hindernissen auf der Strecke (Hammer, Wasser). Dies sorgt für unregelmäßige und schwer vorhersagbare Ereignisse. Ebenfalls visuell darzustellen.

#### Mindestens 5 Eingabeparameter
* Der Anwender kann vor dem Start über eine UI folgende fünf physikalische Eigenschaften seiner Murmel per Schieberegler einstellen:
    * **Masse**
    * **Reibung**
    * **Elastizität (Bounciness)**
    * **Größe (Skalierung)**
    * **Anfangsimpuls**
    * **mehr austehend**

#### Variable Simulationsgeschwindigkeit
* Die Benutzeroberfläche bietet Steuerungselemente, um die globale Simulationsgeschwindigkeit auf folgende Stufen zu setzen:
    * **Pause (0x)**
    * **Langsam (0.5x)**
    * **Normal (1.0x)**
    * **Schnell (2.0x)**
    * **Sehr Schnell (4.0x)**

#### Visuelle Darstellung und Auswertung
* Die 3D-Simulation wird durch einen eigenen Auswertungsbildschirm nach dem Rennen ergänzt.
* Dieser Bildschirm zeigt Endzeiten und Platzierungen an und setzt sie in Relation zu den gewählten Startparametern.
* Zur besseren Visualisierung werden die Daten durch einfache Balkendiagramme (simuliert mit UMG `ProgressBar`-Widgets) dargestellt.

#### Kleine, passende Animation
* Die primäre Animation ist die physikalisch korrekte Roll- und Kollisionsbewegung der Murmeln. 
* Zusätzliche visuelle Effekte (z.B. Funken bei Kollision, Leuchteffekte bei Boost-Pads) ergänzen die Darstellung.

#### Windows-Anwendung & .exe-Start
* Das Projekt wird über die Unreal Engine für die Plattform "Windows" paketiert. 
* Das Ergebnis ist ein Verzeichnis mit einer MurmelSimulation.exe, die ohne Installation gestartet werden kann.

#### Lauffähigkeit auf Schulrechnern
* Die Performance wird durch gezielte Maßnahmen sichergestellt: C++ für die Kernlogik, statische Beleuchtung (Baked Lighting), Low-Poly-Assets und Optimierung der physikalischen Berechnungen.

#### GUI (Grafische Benutzeroberfläche)
* Der UI-Flow der Anwendung ist klar in drei Bereiche gegliedert:
    * **1. Startmenü:** Dient als Haupteinstiegspunkt zum Starten der Simulation und ist für zukünftige Erweiterungen (z.B. Speicherstände, Weltenauswahl) vorbereitet.
    * **2. Simulations-UI:** Die Hauptansicht, in der die Bahn und Murmelparameter konfiguriert werden. Sie enthält auch die Steuerungselemente für die Simulation (Start, Pause, Geschwindigkeit).
    * **3. Auswertungs-UI:** Ein separater Bildschirm, der nach Abschluss eines Rennens zur detaillierten Anzeige der Ergebnisse dient.

## 2. Nicht-funktionale Anforderungen

#### Clean Code
* Die Kernlogik des Projekts wird in **C++** nach dem offiziellen Unreal Engine Coding Standard entwickelt.
* Es wird eine klare Trennung von Logik (C++) und Darstellung/UI (Blueprints/UMG) eingehalten, um die Wartbarkeit und Übersichtlichkeit zu maximieren.

#### UI nach ISO 9241-110
* Die UI wird nach den sieben Interaktionsprinzipien gestaltet:
* Aufgabenangemessenheit: Keine überflüssigen Menüs oder Optionen.
* Selbstbeschreibungsfähigkeit: Alle Regler und Buttons sind klar beschriftet.
* Steuerbarkeit: Der Nutzer hat jederzeit die Kontrolle über Start, Pause und Geschwindigkeit.
* Erwartungskonformität: Die UI verhält sich wie erwartet (z.B. Schieberegler).
* Fehlertoleranz: Falscheingaben werden durch Min/Max-Werte der Regler verhindert.
* Individualisierbarkeit: Nicht relevant für dieses Projekt.
* Lernförderlichkeit: Die direkte visuelle Rückmeldung fördert das Verständnis der Parameter.

#### Benutzerfreundliche Animation & Effekte
* **Kamera:** Es werden unterschiedliche Kamera-Modi für die verschiedenen Spielphasen implementiert (z.B. eine statische Top-Down-Ansicht für die Konfiguration und eine dynamische Verfolgerkamera während des Rennens). Die Kameras werden mit sanften Übergängen und `Camera Lag` für eine angenehme Nutzererfahrung versehen.
* **Visuelle Effekte:** Ein **Trail-Effekt** (Leuchtspur) an den Murmeln verbessert das Geschwindigkeitsgefühl. Zusätzliche Partikeleffekte werden eingesetzt, um wichtige Ereignisse wie Kollisionen oder die Aktivierung von Boost-Pads visuell hervorzuheben.

## 🛠️ Tech Stack

* **Engine:** Unreal Engine 5
* **Sprache:** C++ / Blueprints (Hybrid-Ansatz)
    * **C++:** Wird für die Kernsysteme, Datenstrukturen und performanzkritische Logik verwendet.
    * **Blueprints:** Wird für die Benutzeroberfläche (UMG), einfache Actor-Logik und das Level-Scripting genutzt.
* **Physik:** Unreal Chaos Physics
* **Plattform:** Windows (64-bit)

## 🚀 Setup & Installation

Die Anwendung wird als eigenständige **Windows-Anwendung** ausgeliefert und kann über eine `.exe`-Datei gestartet werden.

1.  Laden Sie das neueste Release von der [Releases-Seite](https://github.com/DEIN_BENUTZERNAME/DEIN_REPO/releases) herunter.
2.  Entpacken Sie die ZIP-Datei.
3.  Führen Sie die `MurmelSimulation.exe` aus.
4.  Es ist keine weitere Installation notwendig.

## 📂 Projektmanagement

* **Vorgehensmodell:** Das Projekt folgt dem **Wasserfallmodell**, da die Anforderungen von Beginn an klar und unveränderlich definiert sind.
* **Dokumentation:** Die vollständige Projektdokumentation nach IHK-Standard wird separat bereitgestellt und ist nicht Teil dieses Repositories.
* **Benutzerhandbuch:** Ein detailliertes Benutzerhandbuch in deutscher und englischer Sprache wird mit dem finalen Release digital zur Verfügung gestellt.

## 📜 Lizenz

Dieses Projekt steht unter der [MIT License](LICENSE).