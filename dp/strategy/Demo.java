package dp.strategy;
public class Demo {
	public static void main(String[] args) {
		YanShuiDuck ysd = new YanShuiDuck();
		YanShuiDuck ysd1 = new YanShuiDuck(new CannotFly(), new CannotQuack(), false);
		YellowDuck yd = new YellowDuck();

		ysd.flyPerformance();
		ysd1.flyPerformance();
		yd.flyPerformance();

		ysd.quackPerformance();
		ysd1.quackPerformance();
		yd.quackPerformance();

		yd.setFlyBehavior(new CannotFly());
		yd.setQuackBehavior(new CannotQuack());

		yd.flyPerformance();
		yd.quackPerformance();
	}
}


