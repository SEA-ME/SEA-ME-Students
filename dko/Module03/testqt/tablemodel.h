#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>

struct Contact
{
    QString name;
    QString email;
    QString phone_number;
    bool bookmarked; // New field

    bool operator==(const Contact &other) const
    {
        return name == other.name && phone_number == other.phone_number && email == other.email && bookmarked == other.bookmarked;
    }
};

inline QDataStream &operator<<(QDataStream &stream, const Contact &contact)
{
    return stream << contact.name << contact.phone_number << contact.email << contact.bookmarked; // Include bookmarked
}

inline QDataStream &operator>>(QDataStream &stream, Contact &contact)
{
    return stream >> contact.name >> contact.phone_number >> contact.email >> contact.bookmarked; // Include bookmarked
}

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TableModel(QObject *parent = 0);
    TableModel(QList<Contact> contacts, QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    QList<Contact> getContacts() const;

private:
    QList<Contact> contacts;
};

#endif // TABLEMODEL_H
