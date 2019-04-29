package factory.factory_class.pizza_store;
import  factory.factory_class.pizza;
import  factory.factory_class.factory;

public class PizzaStore {
	void orderPizza(int pizzaType) {
		Pizza p = PizzaFactory.createPizza(pizzaType);
		
		p.prepare();
		p.cook();
		p.cut();
		p.fetch();
	}
}


	
