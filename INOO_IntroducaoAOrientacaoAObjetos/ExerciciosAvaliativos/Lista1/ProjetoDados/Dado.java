import java.util.Random;

public class Dado {
    private int lados = 6;

    public int jogarDado(){

        return randomNumber();
    }

    public int randomNumber(){
        Random gerador = new Random();

        int numDado = gerador.nextInt(lados) + 1;

        return numDado;
    }

}