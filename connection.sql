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

-- Create a table for NPCs
CREATE TABLE npcs (
    npc_id INT AUTO_INCREMENT PRIMARY KEY,
    npc_type VARCHAR(50),
    npc_name VARCHAR(100),
    health INT,
    level INT
);

-- Create a table for NPC drops (what items NPCs can drop when defeated)
CREATE TABLE npc_drops (
    drop_id INT AUTO_INCREMENT PRIMARY KEY,
    npc_id INT,
    item_name VARCHAR(100),
    drop_probability FLOAT,
    FOREIGN KEY (npc_id) REFERENCES npcs(npc_id)
);

-- Create a table for towns
CREATE TABLE towns (
    town_id INT AUTO_INCREMENT PRIMARY KEY,
    town_name VARCHAR(100)
);

-- Create a table for shops within the towns
CREATE TABLE shops (
    shop_id INT AUTO_INCREMENT PRIMARY KEY,
    town_id INT,
    shop_name VARCHAR(100),
    FOREIGN KEY (town_id) REFERENCES towns(town_id)
);

-- Create a table for items available in the shops (linking items to shops)
CREATE TABLE shop_items (
    shop_item_id INT AUTO_INCREMENT PRIMARY KEY,
    shop_id INT,
    item_name VARCHAR(100),
    price INT,
    quantity INT,
    FOREIGN KEY (shop_id) REFERENCES shops(shop_id)
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

-- Insert NPCs (orc and goblin)
INSERT INTO npcs (npc_type, npc_name, health, level) VALUES
('Orc', 'Grarg', 100, 5),
('Goblin', 'Snik', 50, 3);

-- Insert NPC drops
INSERT INTO npc_drops (npc_id, item_name, drop_probability) VALUES
(1, 'Orc Sword', 0.25),
(1, 'Orc Shield', 0.15),
(2, 'Goblin Dagger', 0.30);

-- Insert towns and shops
INSERT INTO towns (town_name) VALUES ('Krendor Castle');
INSERT INTO shops (town_id, shop_name) VALUES (1, 'Krendor Armory');

-- Insert items into shop
INSERT INTO shop_items (shop_id, item_name, price, quantity) VALUES
(1, 'Leather Armor', 100, 10),
(1, 'Iron Sword', 150, 5),
(1, 'Healing Potion', 50, 20);