package dp.strategy;
public class Demo {
	public static void main(String[] args) {
		YanShuiDuck ysd = new YanShuiDuck();
		YanShuiDuck ysd1 = new YanShuiDuck(new CannotFly(), new CannotQuack(), false);
		YellowDuck yd = new YellowDuck();

		ysd.fly();
		ysd1.fly();
		yd.fly();

		ysd.quack();
		ysd1.quack();
		yd.quack();

		yd.setFlyBehavior(new CannotFly());
		yd.setQuackBehavior(new CannotQuack());

		yd.fly();
		yd.quack();
	}
}


