// Ejemplo de Productor-Consumidor utilizando Monitores en Java
//
//  Sistemas Operativos
// UNPSJB - Trelew

import java.util.*;

public class ProductorConsumidor {

	static final int N = 30;
	static Productor productor = new Productor();
	static Consumidor consumidor = new Consumidor();
	static Monitor mon = new Monitor();
	static Random random = new Random();
	static Inspector inspector = new Inspector();

	public static void main(String args[])
	{
		inspector.start();
		productor.start();
		consumidor.start();
	}

	static class Productor extends Thread {
		
		private int valor = 0;
		
		public void run()
		{
			int item;

			while(true)
			{
				item = producirItem();
				mon.insertar(item);
			}
		}

		private int producirItem()
		{
			try {
				sleep(1000 + random.nextInt(1000));
			} catch(InterruptedException e) { /* Hacer algo con este error ... */ }

			return valor++;
		}
	}

	static class Consumidor extends Thread {

		public void run()
		{
			int item;

			while(true)
			{
				item = mon.remover();
				consumirItem(item);
			}
		}

		private void consumirItem(int item)
		{
			System.out.println(item);

			try {
				sleep(9500 + random.nextInt(1000));
			} catch(InterruptedException e) { /* Hacer algo con este error ... */ }
		}
	}
	
	static class Monitor {
		
		private int buffer[] = new int[N];
		private int cant = 0, inicio = 0, fin = 0;

		public synchronized void insertar(int val)
		{
			while(cant == N)
				dormir();

			buffer[fin] = val;
			fin = (fin + 1) % N;
			cant = cant + 1;
			if(cant == 1)
				notify();
		}

		public synchronized int remover()
		{
			int val;

			while(cant == 0)
				dormir();

			val = buffer[inicio];
			inicio = (inicio + 1) % N;
			cant = cant - 1;
			if(cant == (N - 1))
				notify();

			return val;
		}

		public synchronized int usoBuffer()
		{
			return cant;
		}

		private void dormir()
		{
			try {
				wait();
			} catch(InterruptedException e) { /* Hacer algo con este error ... */ }
		}
	}

	static class Inspector extends Thread {

		public void run()
		{
			while(true)
			{
				int uso;

				try {
					sleep(1000);
				} catch(InterruptedException e) { /* Hacer algo con este error ... */ }

				uso = mon.usoBuffer();
				System.out.print('[');
				for(int i = 0; i < uso; ++i)
				{
					System.out.print('*');
				}
				for(int i = uso; i < N; ++i)
				{
					System.out.print(' ');
				}
				System.out.println(']');
			}
		}
	}
}

