using System;

namespace CMPE312_Lab_4
{
    class Circle
    {
        protected double radius;
        protected string color;

        public Circle()
        {
            radius = 1.0;
            color = "red";
        }

        public Circle(double radius, string color)
        {
            this.radius = radius;
            this.color = color;
        }

        public double getArea(double radius)
        {
            return 3.14 * radius * radius; 
        }
    }

    class Cylinder : Circle
    {
        private double height;

        public Cylinder()
        {
            height = 1.0;
        }

        public Cylinder(double radius, string color, double height)
        {
            this.radius = radius;
            this.color = color;
            this.height = height;
        }

        public double getVolume(double radius, double height)
        {
            return 3.14 * radius * radius * height;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Circle test = new Circle();
            Console.WriteLine(test.getArea(10));
            Cylinder test2 = new Cylinder();
            Console.WriteLine(test2.getVolume(10, 1));
        }
    }
}
