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