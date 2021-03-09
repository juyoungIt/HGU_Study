// #2. CH05_MySpeciesFifthTry
// 작성자 : 21700760 하주영

import java.util.Scanner;

public class CH05_MySpeciesFifthTry
{	
	private String name;
	private int population;
	private double growthRate;
	
	// 프로그램에 필요한 값들을 사용자로부터 입력받음
	public void readInput()
	{
		Scanner keyboard = new Scanner(System.in);
		System.out.println("What is the species's name?");
		name = keyboard.nextLine();
		
		System.out.println("What is the population of the species?");
		population = keyboard.nextInt();
		if(population < 0) { // 예외처리,유효하지 않은 값이 입력된 경우
			System.out.println("ERROR : using a negative population");
			System.exit(0); // 프로그램 종료
		}
		
		System.out.println("Enter growth rate (% increase per year):");
		growthRate = keyboard.nextDouble();
		keyboard.close();
	}
	
	// 사용자에게 입력받은 값에 대한 출력
	public void writeOutput()
	{
		System.out.println("Name : " + name);
		System.out.println("Population : " + population);
		System.out.println("growthRate : " + growthRate + "%");
	}
	
	// 개체수를 예측
	public int predictPopulation(int years)
	{
		int result = 0;
		double populationAmount = population;
		int count = years;
		while((count>0) && (populationAmount>0))
		{
			populationAmount = (populationAmount+(growthRate / 100) * populationAmount);
			count --;
		}
		if(populationAmount>0)
			result = (int)populationAmount;
		
		return result;
	}
	
	public String getName()
	{
		return name;
	}
	
	public int getPopulation()
	{
		return population;
	}
	
	public double getGrowthRate()
	{
		return growthRate;
	}
	
	// object에 필요한 3개의 값을 한번에 받아서 초기화
	public void setSpecies(String newName, int newPopulation, double newGrowthRate)
	{
		name = newName;
		if(newPopulation >= 0)
			population = newPopulation;
		else
		{
			System.out.println("\"Error\" : using a negative population");
			System.exit(0);
		}
		growthRate = newGrowthRate;
	}
	
	// 해당 object의 name을 초기화
	public void setName(String newName)
	{
		name = newName;
	}
	
	// 해당 object의 population 초기화
	public void setPopulation(int newPopulation)
	{
		if(newPopulation >= 0)
			population = newPopulation;
		else
		{
			System.out.println("\"Error\" : using a negative population");
			System.exit(0);
		}
	}
	
	// 해당 object의 growthRate 초기화
	public void setGrowthRate(double newGrowthRate)
	{
		growthRate = newGrowthRate;
	}
}
