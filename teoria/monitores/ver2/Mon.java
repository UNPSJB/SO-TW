public class Mon {

	private int indice;
	int[] spool;
	private int procActivos;

	public Mon() {
		indice = 0;
		spool = new int[2000001];
		procActivos = 2;
	}

	public synchronized void exec() throws InterruptedException {
		Proc_A pa = new Proc_A( this );
		Proc_B pb = new Proc_B( this );
		pa.start();
		pb.start();
		while( procActivos > 0 )
			wait();
		printInformes();
	}

	//public void add( int value ) {
	public synchronized void add( int value ) {
		int temp1, temp2 = 0;

		temp1 = indice;
		spool[temp1] = value;
		++temp1;
		while( temp2 < 100 )
			++temp2;
		indice = temp1;
	}

	public synchronized void chau() {
		if( --procActivos == 0 )
			notify();
	}

	private void printInformes() {
		int cant1 = 0, cant2 = 0;

		for( int i = 0; i < indice; ++i )
			if( spool[i] == 1 )
				++cant1;
			else if ( spool[i] == 2 )
				++cant2;
		System.out.println( "indice = " + indice );
		System.out.println( "spool[0] = " + spool[0] );
		System.out.println( "spool[indice - 1] = " + spool[indice - 1] );
		System.out.println( "Cantidad de unos = " + cant1 );
		System.out.println( "Cantidad de dos = " + cant2 );
	}

	public static void main( String args[] ) {
		Mon prog;

		prog = new Mon();
		try {
			prog.exec();
		} catch ( Exception e ) {
			e.printStackTrace();
		}
	}
}
