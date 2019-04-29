package factory.factory_class.pizza;

public class NYPizza extends Pizza {
	NYPizza() {
		this.name = "New york pizza";
	}

	void prepare() {
		System.out.println("to cook the New york pizza, we need"+
			"onion , cheese, potato...");
	}
}

