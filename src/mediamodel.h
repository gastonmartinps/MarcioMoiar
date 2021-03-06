/*
 * SPDX-FileCopyrightText: (C) 2017 Atul Sharma <atulsharma406@gmail.com>
 * SPDX-FileCopyrightText: (C) 2017 by Marco Martin <mart@kde.org>
 * SPDX-FileCopyrightText: (C) 2021 Zhang He Gang <zhanghegang@jingos.com>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef MEDIAMODEL_H
#define MEDIAMODEL_H

#include <QSize>
#include <QVariant>
#include <kdirmodel.h>
#include "types.h"

class QTimer;

/**
 * This class provides a QML binding to KDirModel
 * Provides an easy way to navigate a filesystem from within QML
 *
 * @author Marco Martin <mart@kde.org>
 */
class MediaModel : public KDirModel
{
    Q_OBJECT

    /**
     * @property string The url we want to browse. it may be an absolute path or a correct url of any protocol KIO supports
     */
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

    /**
     * @property count Total number of rows
     */
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    MediaModel(QObject *parent = 0);
    virtual ~MediaModel();

    QHash<int, QByteArray> roleNames() const override;

    void setUrl(QString &url);
    QString url() const;

    QVariant data(const QModelIndex &index, int role) const override;
    int count() const
    {
        return rowCount();
    }

    Q_INVOKABLE int indexForUrl(const QString &url) const;

    Q_INVOKABLE QVariantMap get(int index) const;

    /**
     * Helper method to empty the trash
     */
    Q_INVOKABLE void emptyTrash();

Q_SIGNALS:
    void countChanged();
    void urlChanged();
    void mimeTypeChanged();

private:
    QStringList m_mimeTypes;
    QString m_imagePath;
};

#endif // IMAGEFOLDERMODEL_H
