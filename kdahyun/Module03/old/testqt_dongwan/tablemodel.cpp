#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

TableModel::TableModel(QList<Contact> contacts, QObject *parent)
    : QAbstractTableModel(parent)
    , contacts(contacts)
{
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return contacts.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= contacts.size() || index.row() < 0)
        return QVariant();

    const auto &contact = contacts.at(index.row());

    if (role == Qt::DisplayRole) {
        if (index.column() == 0)
            return contact.name;
        else if (index.column() == 1)
            return contact.phone_number;
        else if (index.column() == 2)
            return contact.email;
        else if (index.column() == 3)
            return contact.bookmarked ? "Yes" : "No";
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Name");
            case 1:
                return tr("Phone Number");
            case 2:
                return tr("Email");
            case 3:
                return tr("Bookmarked");
            default:
                return QVariant();
        }
    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();

        auto contact = contacts.value(row);

        if (index.column() == 0)
            contact.name = value.toString();
        else if (index.column() == 1)
            contact.phone_number = value.toString();
        else if (index.column() == 2)
            contact.email = value.toString();
        else if (index.column() == 3)
            contact.bookmarked = value.toBool();
        else
            return false;

        contacts.replace(row, contact);
        emit dataChanged(index, index, {role});

        return true;
    }

    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    Qt::ItemFlags flags = QAbstractTableModel::flags(index);

    if (index.column() == 3) // Bookmark column is editable
        flags |= Qt::ItemIsEditable;

    return flags;
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        contacts.insert(position, {QString(), QString(), QString(), false});

    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        contacts.removeAt(position);

    endRemoveRows();
    return true;
}

QList<Contact> TableModel::getContacts() const
{
    return contacts;
}
