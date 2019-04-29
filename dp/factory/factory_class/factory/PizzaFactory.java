package factory.factory_class.factory;
import  factory.factory_class.pizza;

public class PizzaFactory {
	static Pizza createPizza(int pizzaType) {
		switch (pizzaType) {
			case 1:
				return(new NYPizza());
				break;
			case 2:
				return(new ChicagoPizza());
				break;
			default:
				return null;
				break;
		}
	}
}



