#ifndef CROWD_INFLUENCE_H
#define CROWD_INFLUENCE_H

#include <string>
#include <vector>

// Forward declarations
class Crowd;
class Stadium;
class Team;
class Player;
class EventTracker;
class MomentumEffect;
class AudioManager;

/**
 * Represents the overall game state.
 */
class Game {
private:
    int currentScore;
    int gameTime;
    bool isRivalry;

    Stadium* stadium;
    EventTracker* eventTracker;
    std::vector<Team*> teams;

public:
    Game();

    void startGame();
    void updateGameState();
};

/**
 * Represents the stadium where the game is played.
 */
class Stadium {
private:
    std::string name;
    std::string weather;
    bool isHomeTeam;

    Crowd* crowd;

public:
    Stadium(const std::string& stadiumName);

    int getAtmosphereLevel() const;
};

/**
 * Manages crowd behavior and reactions.
 */
class Crowd {
private:
    int intensity;
    std::string mood;
    int size;

    AudioManager* audioManager;

public:
    Crowd();

    void updateMood(const std::string& eventType);
    void calculateIntensity();
    void triggerReaction();
};

/**
 * Tracks in-game events that affect the crowd.
 */
class EventTracker {
private:
    std::string lastEvent;
    int eventImportance;

public:
    EventTracker();

    void logEvent(const std::string& eventType);
    void notifyCrowd(Crowd* crowd);
};

/**
 * Represents a football team.
 */
class Team {
private:
    std::string teamName;
    int morale;
    std::vector<Player*> players;

public:
    Team(const std::string& name);

    void updateMorale();
};

/**
 * Represents an individual player.
 */
class Player {
private:
    int energy;
    int focus;
    std::string performanceStats;

public:
    Player();

    void applyEffect(const MomentumEffect& effect);
    void updatePerformance();
};

/**
 * Applies temporary momentum-based effects to players.
 */
class MomentumEffect {
private:
    int boostAmount;
    int duration;

public:
    MomentumEffect(int boost, int durationSeconds);

    void calculateEffect(int crowdIntensity);
    void applyToPlayer(Player* player);
};

/**
 * Handles audio feedback such as cheers and boos.
 */
class AudioManager {
private:
    int volumeLevel;

public:
    AudioManager();

    void playCheer();
    void playBoo();
    void playChant();
};

#endif // CROWD_INFLUENCE_H

