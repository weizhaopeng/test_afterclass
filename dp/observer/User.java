package dp.observer;

public class User implements Observer, Display {
	private WeatherData wd;
	public void update(Object o) {
		if (o instanceof WeatherData) {
			wd = (WeatherData)o;
			displayData(wd);
		}
	}

	public void displayData(WeatherData wd) {
		System.out.println("temperature is :"+wd.getTemperature());
		System.out.println("humidity is :"+wd.getHumidity());
		System.out.println("wind speed is :"+wd.getWindSpeed());
	}
}

			
