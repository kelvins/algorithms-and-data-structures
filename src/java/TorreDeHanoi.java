
public class TorreDeHanoi {

	public static void main(String [] args){
		TorreDeHanoi(0, 2, 1, 8);
	}
	
	public static void TorreDeHanoi(int ori, int dst, int aux, int qnt){
		if(qnt == 1){
			System.out.println("Move de " + ori + " para " + dst);
		}else{
			TorreDeHanoi(ori, aux, dst, qnt-1);
			TorreDeHanoi(ori, dst, aux, 1);
			TorreDeHanoi(aux, dst, ori, qnt-1);
		}
	}
	
}
