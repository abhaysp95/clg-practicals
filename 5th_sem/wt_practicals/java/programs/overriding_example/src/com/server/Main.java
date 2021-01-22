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
	Beerus(String name) {
		super(name);
	}
	@Override
	void signature_move() {
		System.out.println("Famous move: Sphere of Destruction!!!");
	}
}

class Goku extends DBZ {
	Goku(String name) {
		super(name);
	}
	@Override
	void signature_move() {
		System.out.println("Famous move: Kamehameha!!!");
	}
}

class Vegeta extends DBZ {
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