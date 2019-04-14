package dp.decorate.decorate;
import dp.decorate.beverage.*;

public abstract class Condiment extends Beverage {
	private Beverage beverage;

	Condiment(Beverage b) {
		this.beverage = b;
	}

	abstract String getDescription();
}

class ZhenZhu extends Condiment {
	String getDescription() {
		return(beverage.getDescription+", +zhenzhu");
	}
}

class YeGuo extends Condiment{
	String getDescription() {
		return(beverage.getDescription+", +yeguo");
	}
}

class BuDing extends Condiment {
	String getDescription() {
		return(beverage.getDescription+", +buding");
	}
}


