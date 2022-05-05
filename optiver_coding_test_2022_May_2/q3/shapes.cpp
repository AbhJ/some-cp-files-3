/**
 * @author      : acer (acer@abj-ubuntu)
 * @file        : shapes
 * @created     : Sunday May 01, 2022 10:07:53 IST
 */

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
	interface Shape {
		int GetArea();
	}

	static class Rectangle implements Shape {
		private double length;
		private double breadth;

		public Rectangle (double length, double breadth) {
			this.length = length;
			this.breadth = breadth;
		}

		@Override
		public int GetArea() {
			return (int)Math.round (length * breadth);
		}
	}

	static class Circle implements Shape {

		private double radius;

		public Circle (double radius) {
			this.radius = radius;
		}

		@Override
		public int GetArea() {
			return (int)Math.round (3.14 * radius * radius);
		}
	}

	static class Triangle implements Shape {

		private double height, width;

		public Triangle (double height, double width) {
			this.height = height;
			this.width = width;
		}

		@Override
		public int GetArea() {
			return (int)Math.round (height * width / 2.0);
		}
	}

	public static void main (String[] args) throws IOException {
		Scanner in = new Scanner (System.in);
		String rawInput;
		try {
			rawInput = in.nextLine();
			String[] parameters = rawInput.split (" ");
			int rectHeight = Integer.parseInt (parameters[0]);
			int rectWidth = Integer.parseInt (parameters[1]);
			int triHeight = Integer.parseInt (parameters[2]);
			int triWidth = Integer.parseInt (parameters[3]);
			int cirRadius = Integer.parseInt (parameters[4]);
			int totalArea = 0;
			List<Shape> shapes = new ArrayList<>();
			shapes.add (new Rectangle (rectHeight, rectWidth));
			shapes.add (new Triangle (triHeight, triWidth));
			shapes.add (new Circle (cirRadius));
			for (Shape shape : shapes)
				totalArea += shape.GetArea();
			System.out.println (String.valueOf (totalArea));
		}
		catch (Exception e) {
		}
	}
}
