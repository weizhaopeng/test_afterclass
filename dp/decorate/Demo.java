package decorate;
import  decorate.*;

public class Demo {
	public static void main(String[] args) {
		Beverage coffee = new BigCap(new YeGuo(new Coffee()));

		System.out.println(coffee.cost());
	}
}


