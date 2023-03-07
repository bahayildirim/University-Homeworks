using System;
using System.Security.Cryptography.X509Certificates;

namespace CMPE312_Lab_4_2
{
    class OEM
    {
        public string name;
        public double price;
        public double dollarexchange;
        public double interest;
        public string brand;

        public OEM()
        {
            dollarexchange = 3.72;
            interest = 0.18;
        }

        public OEM(string name, double price, string brand)
        {
            this.name = name;
            this.price = price;
            this.brand = brand;
            dollarexchange = 3.72;
            interest = 0.18;
        }

        public double setPrice(double price)
        {
            this.price = price;
            if(this.price < 0)
            {
                Console.WriteLine("ERROR: Price cannot be negative!");
                Console.ReadKey();
            }
            return this.price;
        }
        public double calculatePrice()
        {
            return (price * dollarexchange) + (price * dollarexchange * interest);
        }

        public override string ToString()
        {
            return "Name: " + name + " Price: " + price + " Brand: " + brand; 
        }

    }

    class CPU : OEM
    {
        public double clockspd;
        public double cache;
        public double memwidth;
        public double serialno;

        public CPU(double clockspd, double cache, double memwidth, double serialno)
        {
            this.clockspd = clockspd;
            this.cache = cache;
            this.memwidth = memwidth;
            this.serialno = serialno;
        }

        public override string ToString()
        {
            return "Name: " + name + " Price: " + price + " Brand: " + brand + " Clock Speed: " + clockspd + " Cache: " + cache + " Memory Width: " + memwidth + " Serial Number: " + serialno;
        }

    }

    class GPU : OEM
    {
        public double memspd;
        public double ramcapacity;
        public double meminterface;
        public double serialno;

        public GPU(double memspd, double ramcapacity, double serialno)
        {
            this.memspd = memspd;
            this.ramcapacity = ramcapacity;
            this.serialno = serialno;
        }

        public override string ToString()
        {
            return "Name: " + name + " Price: " + price + " Brand: " + brand + " Memory Speed: " + memspd + " Ram Capacity: " + ramcapacity + " Serial Number: " + serialno;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
           OEM testoem = new OEM("testname", 10, "testbrand");
           Console.WriteLine(testoem.calculatePrice());
        }
    }
}
