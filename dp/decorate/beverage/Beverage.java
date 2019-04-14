package dp.decorate.beverage;

public abstract class Beverage {
	private String description = "beverage";
	private double price = 0;

	String getDescription() {
		return this.description;
	}

	abstract double cost();
}

public class Coffee extends Beverage {
	Coffee() {
		this.price = 10;
		this.description = new String("coffee:");
	}
	Coffee(double priceIn) {
		this.price = priceIn;
		this.description = new String("coffee:");
	}

	double cost() {
		return this.price;
	}
}

public class MilkTea extends Beverage {
	MilkTea() {
		this.price = 12;
		this.description = new String("milk tea:");
	}
	MilkTea(double priceIn) {
		this.price = priceIn;
		this.description = new String("milk tea:");
	}
	double cost() {
		return this.price;
	}
}

