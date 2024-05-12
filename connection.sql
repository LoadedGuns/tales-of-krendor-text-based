-- Create a table for players
CREATE TABLE players (
    player_id INT AUTO_INCREMENT PRIMARY KEY,
    player_name VARCHAR(255) NOT NULL
);

-- Create a table for player skills
CREATE TABLE player_skills (
    skill_id INT AUTO_INCREMENT PRIMARY KEY,
    player_id INT,
    skill_name VARCHAR(50),
    skill_level INT,
    experience_points INT,
    FOREIGN KEY (player_id) REFERENCES players(player_id)
);

-- Create a table for inventory items
CREATE TABLE inventory_items (
    item_id INT AUTO_INCREMENT PRIMARY KEY,
    player_id INT,
    item_type VARCHAR(50),
    item_name VARCHAR(100),
    quantity INT,
    FOREIGN KEY (player_id) REFERENCES players(player_id)
);

-- Insert initial skill data (fishing and cooking)
INSERT INTO player_skills (player_id, skill_name, skill_level, experience_points) VALUES
(1, 'Fishing', 1, 0),
(1, 'Cooking', 1, 0);

-- Insert initial inventory items (armor, weapons, shields, food, and gold)
INSERT INTO inventory_items (player_id, item_type, item_name, quantity) VALUES
(1, 'Armor', 'Iron Armor', 1),
(1, 'Weapon', 'Iron Sword', 1),
(1, 'Shield', 'Iron Shield', 1),
(1, 'Food', 'Shark', 10),
(1, 'Gold', 'Coins', 100);
