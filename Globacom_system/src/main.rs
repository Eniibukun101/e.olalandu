use std::fs;
use std::io::{self, Write};

fn main() {
    println!("Hi! Welcome to Globacom Ltd's Management Access Application.");
    println!("Select your position (1-5) to access the appropriate database structure:");
    println!("1. Administrator");
    println!("2. Project Manager");
    println!("3. Employee");
    println!("4. Customer");
    println!("5. Vendor");

    print!("Enter your choice: ");
    io::stdout().flush().unwrap();

    let mut input = String::new();
    if io::stdin().read_line(&mut input).is_err() {
        println!("Failed to read input.");
        return;
    }

    let position: u32 = match input.trim().parse() {
        Ok(num) => num,
        Err(_) => {
            println!("Invalid input. Please enter a number between 1 and 5.");
            return;
        }
    };

    let file_name = match position {
        1 => "globacom_dbase1.sql",
        2 => "project_table.sql",
        3 => "staff_table.sql",
        4 => "customer_table.sql",
        5 => "dataplan_table.sql",
        _ => {
            println!("Invalid position selected.");
            return;
        }
    };

    println!("\nLoading database structure...\n");

    match fs::read_to_string(file_name) {
        Ok(contents) => println!("{}", contents),
        Err(_) => println!("Sorry, the requested database file could not be found."),
    }
}

