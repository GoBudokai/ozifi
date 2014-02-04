#pragma once

#include <unordered_map>

#include <QObject>
#include <QImage>
#include <QColor>

struct TPlanetKey {
    size_t Type;
    size_t Diameter;
    QColor Color;
};

struct TPlanetKeyHash {
    size_t operator()(const TPlanetKey& key) const;
};

struct TPlanetKeyCompare {
    bool operator()(const TPlanetKey& a, const TPlanetKey& b) const;
};

typedef std::unordered_map<TPlanetKey, QImage, TPlanetKeyHash, TPlanetKeyCompare> TPlanetCache;

class TGraphicManager : public QObject
{
    Q_OBJECT
public:
    explicit TGraphicManager(QObject *parent = 0);
    const QImage& GetImage(size_t planetType, size_t diameter, QColor color);
    void ClearCache();
private:
    std::vector<QImage> PlanetImages;
    TPlanetCache PlanetCache;
};