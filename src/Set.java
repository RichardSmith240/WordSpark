import java.io.File;
import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;

public class Set {

	public static String importFile(String path) {
		String rawSet = "";

		try (BufferedReader fs = new BufferedReader(new FileReader(path))) {
			String line;

			while ((line = br.readLine()) != null) {
				System.out.println(line);
				rawSet = rawSet + " " + line;
			}

			fs.close();
		} catch (FileNotFoundException e) {
			System.out.println("File Not Found: "+ file.getName() + "\n" + e);
		} catch (IOExeption e) {
			System.out.println("Error reading file: \n" + e);
		}
		return rawSet;
	}
	public static Queue makeSet(String rawSet) {
		Scanner scnr = new Scanner(System.in);	
		Queue set = new Queue();

		while (scnr.next()) {
			 
		}
	}
}
