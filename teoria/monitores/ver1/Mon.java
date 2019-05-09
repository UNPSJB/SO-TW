// Mon.java
public class Mon {

	private int indice;
	private int procActivos;

	public Mon() {
		indice = 0;
		procActivos = 2;
	}

	public synchronized void exec() throws java.lang.InterruptedException {
		Proc_A pa = new Proc_A( this );
		Proc_B pb = new Proc_B( this );
		pa.start();
		pb.start();
		while ( procActivos > 0 )
			wait();
		System.out.println( "indice = " + indice );
	}

	public void incIndice() {
	//public synchronized void incIndice() {
		int temp1, temp2 = 0;

		temp1 = indice;
		++temp1;
		while( temp2 < 100 )
			++temp2;
		indice = temp1;
	}

	public synchronized void chau() {

		if( --procActivos == 0 )
			notify();
	}

	public static void main( String args[] ) {
		Mon prog;

		prog = new Mon();
		try {
			prog.exec();
		} catch( Exception e ) {
			e.printStackTrace();
		}
	}
}
