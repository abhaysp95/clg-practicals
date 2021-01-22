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