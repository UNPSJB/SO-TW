// Ejemplo de Productor-Consumidor utilizando Monitores en Java
//
// Sistemas Operativos
// UNPSJB - Trelew

public class ProductorConsumidor {

	static final int N = 100;
	static Productor p = new Productor();
	static Consumidor c = new Consumidor();
	static Monitor mon = new Monitor();

	public static void main(String args[])
	{
		p.start();
		c.start();
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
		}

	}
	
	static class Monitor {
		
		private int buffer[] = new int[N];
		private int cant = 0, inicio = 0, fin = 0;

		public synchronized void insertar(int val)
		//public void insertar(int val)
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
		//public int remover()
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

		private void dormir()
		{
			try {
				wait();
			} catch(InterruptedException e) {
				// Hacer algo con este error ...
			}
		}

	}

}

