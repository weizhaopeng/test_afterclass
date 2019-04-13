package dp.decorate.beverage;

public abstract class Beverage {
	String getDescription() {
		return(new String("beverage, "));
	}

	abstract int cost();
}

