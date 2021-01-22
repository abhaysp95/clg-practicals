\newpage

# Core Java Programs

## Program for method overloading

Example demonstrating method overloading in _java_

### Code

```java
package com.server;

public class Main {

	public static int add(int a, int b) {
		return a + b;
	}

	public static double add(double a, double b) {
		return a + b;
	}

	public static double add(String a, String b) {
		return Double.parseDouble(a) + Double.parseDouble(b);
	}

	public static void main(String ...args) {
		System.out.println("int add: " + add(5, 4));
		System.out.println("double add: " + add(5.4, 4.5));
		System.out.println("string add(numeric): " + add("4.5", "5.4"));
	}
}
```

### Output

```
$ java com.server.Main
int add: 9
double add: 9.9
string add(numeric): 9.9
```

## Program for Method overriding

Example demonstrating method overriding in _java_

### Code

```java
package com.server;

abstract class DBZ {
	private String name;
	DBZ(String name) {
		this.name = name;
		System.out.println(this.name + " called");
	}
	abstract void signature_move();
}

class Beerus extends DBZ {
	// God of Destruction
	Beerus(String name) {
		super(name);
	}
	@Override
	void signature_move() {
		System.out.println("Famous move: Sphere of Destruction!!!");
	}
}

class Goku extends DBZ {
	// Most famous character of DBZ world
	Goku(String name) {
		super(name);
	}
	@Override
	void signature_move() {
		System.out.println("Famous move: Kamehameha!!!");
	}
}

class Vegeta extends DBZ {
	// Prince of Saiyans
	Vegeta(String name) {
		super(name);
	}
	@Override
	void signature_move() {
		System.out.println("Famous move: Galick Gun!!!");
	}
}

public class Main {
	public static void main(String ...args) {
		DBZ beerus = new Beerus("Beerus");
		beerus.signature_move();
		System.out.println("-------------------");
		DBZ goku = new Goku("Goku");
		goku.signature_move();
		System.out.println("-------------------");
		DBZ vegeta = new Vegeta("Vegeta");
		vegeta.signature_move();
	}
}
```

### Output

```
$ java com.server.Main
Beerus called
Famous move: Sphere of Destruction!!!
-------------------
Goku called
Famous move: Kamehameha!!!
-------------------
Vegeta called
Famous move: Galick Gun!!!
```

## Write an applet program to draw circle and square

Example demonstrating drawing circle and square with applet in _java_

### Code

```java
package com.server;

import java.awt.*;
import java.applet.*;

public class Shapes extends Applet {
	public void paint(Graphics g) {
		// draw circle
		g.drawOval(10, 10, 50, 50);
		// draw square
		g.drawRect(10, 80, 60, 40);
	}
}

/**
  <applet code="Shapes.class" width="300" height="300"></applet>
*/
```

### Output

Can't show output. `appletviewer` not working on my system for some unexpected reasons right now.

**Practical 1 Finished**
