#ifndef HIGHLIGHTTEXTBOX_H
#define HIGHLIGHTTEXTBOX_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>

namespace Ui {
class HighlightTextBox;
}

class HighlightTextBox : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit HighlightTextBox(QTextDocument *parent = 0);
    ~HighlightTextBox();
public slots:
    void setTextQueue(const QStringList& textQueue);
protected:
    void highlightBlock(const QString &text) override;
private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;
    QTextCharFormat keywordFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat commentFormat;
    //Ui::HighlightTextBox *ui;
};

#endif // HIGHLIGHTTEXTBOX_H
