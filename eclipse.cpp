//============================================================================
// Name        : try-catch.cpp
// Author      : neuseeland89
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/**/

/*Im Laufe der Zeit hat sich das Prinzip des Exception-Handlings (wörtl. aus dem Englischen übersetzt "Ausnahmebehandlung") durchgesetzt. Es basiert grob gesagt darauf, dass durch einen ungewöhnlichen oder nicht eingeplanten Zustand im Programm Exceptions ausgelöst werden, welche an einer zentralisierten Stelle abgefangen und behandelt werden kann. Es erwies sich als effizient einsetzbar, praktisch vorteilhaft und vor allen Dingen von den Methoden und Algorithmen des Programms gelöste Art der Fehlerbehandlung, wie sie beispielsweise die aus C bekannte Technik - bei welcher anhand des Rückgabewertes einer Funktion der Erfolg derselben geprüft wurde - nicht bot!

In C++ gibt es drei Schlüsselwörter, welche Ihnen bei der alltäglichen Fehlerbehandlung sehr oft begegnen werden (es soll sogar Programme geben, die von den folgenden Schlüsselwörtern mehr beinhalten, als if-Zweige!). Im Übrigen haben auch viele andere Programmiersprachen (etwa PHP oder JAVA) die Namen dieser Schlüsselwörter für ihre jeweiligen Implementationen des Exception-Handlings übernommen, Sie sind also in guter Gesellschaft!

try
"try" leitet einen Block ein, welcher den risikobehafteten Code umschließt. Es kann als eine Art Gruppierung aufgefasst werden, die jene Codesequenzen gruppiert, auf die mit dem zweiten Schlüsselwort "catch" (s. unten) in dem Fall, dass innerhalb des Blockes mit "throw" (s. unten) eine Exception ausgelöst wird, zentralisiert reagiert werden soll.

catch
"catch" wird genutzt, um beim Auftreten einer Exception (s. unten) zentralisiert auf diese zu reagieren. Diesem Schlüsselwort kann als Begriff entweder eine Typdeklaration (optionaler Modifizierer, Typ und optionaler Name) übergeben werden, oder drei aufeinander folgende Punkte ("...", ohne die Anführungszeichen); im Falle einer Typdeklaration passt die catch-Anweisung auf Exceptions eben dieses Typs, im Falle der drei Punkte auf Exceptions jedes beliebigen Typs (dazu später mehr). So kann auf unterschiedliche Fehler unterschiedlich reagiert werden. Das Schlüsselwort "catch" kann man sich so ähnlich vorstellen wie das "case" in einer "switch"-Verzweigung, die übergebenen Klasseninstanzen und/oder Variablen als die Bedingungen hinter dieser case-Anweisung und die catch-Anweisung mit den drei Punkten als die "default:"-Anweisung.
Eine einzelne catch-Anweisung mit Typdeklaration - z.B. "catch(const int &MyException)" - wird als "Exception-Handler" bezeichnet. In diesem Beispiel passt er auf alle Exceptions vom Typ int.

Ein Exception-Handler passt auch dann auf eine Exception, wenn diese einen vom Typ des Exception-Handlers abgeleiteten Typ besitzt.

Innerhalb eines Exception-Handlers kann mit Hilfe von throw auch erneut eine Exception geworfen, oder, durch das einfache verwenden von throw ohne weitere Angaben ("throw;", ohne die Anführungszeichen) die Exception, auf die der Exception-Handler angesprungen ist, auch "weiter werfen". Das Stack Unwinding setzt sich somit fort, obwohl die Exception bereits von einem Handler behandelt wurde (nur dass dieser sie eben erneut geworfen, also so gut wie "weiter gegeben" hat). Näheres zum Stack Unwinding in Kapitel 4.

throw
Mit "throw" wird innerhalb einer Funktion eine Exception ausgelöst, auf die ein passender Exception-Handler "anspringt". throw wird eine Instanz eines beliebigen Datentyps oder, was der Sache wesentlich mehr Flexibilität verleiht, einer beliebigen Klasse übergeben (häufig wird diese Instanz in der throw-Anweisung selbst erzeugt). An diesem Datentyp bzw. dieser Klasse wird dann geprüft, ob ein Exception Handler vorhanden ist, welcher auf eben jene Klasse passt.
Beim Auftreten einer Exception werden die Destruktoren aller lokalen Objektinstanzen aufgerufen, sowie der Speicher aller lokalen (nicht statischen) Variablen freigegeben! */

#include <iostream>

using namespace std;

/*Ausnahmefunktion zu überprüfung ob der Output > Input ist*/
int check (int cx, int cx_1, int cx_2)
{
	if (cx < cx_1)						//Wenn Output < Input ~> verwerfe Output/ Lösung ...
		throw 	std::overflow_error("addition overflow");				//... ~> verwerfe Output/ Lösung ...
	return cx;							// ... sonste gebe Output wieder
}

int main()
{
	int x,x_1=1,x_2=0;
	int n;

	/*Generierung einer Fibonacci-Reihe*/
	for (int i=2; i<=n;i++)
	{

		x = x_1 + x_2;			//errechne Fibonacci-Wert

		/*überprüfe Ausnahmen*/
		try				//überprüfe die Ausnahmefkt.
		{
			check(x, x_1,x_2);
		}
		catch(string &e)		//wenn Ausnahme eintritt
		{
			cerr << e << endl;
			
			x = x_1;		//vertausche die x-Werte damit Zeile 69 & 70 keine Auswirkung haben
			x_1 = x_2;
			
			return x;
			return x_1;
		}
				
		cout << "Pos." << i << ": " <<  x  << endl;

		/*Vertausche die x-Werte zur Bildung der Fib-Reihe*/
		x_2=x_1;
		x_1=x;
	}

	return 0;
}
