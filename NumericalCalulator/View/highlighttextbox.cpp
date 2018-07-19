#include "highlighttextbox.h"
#include <QColor>
//#include "ui_HighlightTextBox.h"

HighlightTextBox::HighlightTextBox(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    //keyword format
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bdraw\\b"
                    << "\\bComputeDeterminant\\b"
                    << "\\bSolvePoly\\b"
                    << "\\binvert\\b"
                    << "\\btranspose\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    //number format
    HighlightingRule numberRule;
    numberFormat.setForeground(QColor(237, 145, 33, 255));//orange color for number
    //numberFormat.setFontItalic(true);
    numberRule.pattern = QRegularExpression("[0-9]{1,30}");
    numberRule.format = numberFormat;
    highlightingRules.append(numberRule);

    //comment format
    HighlightingRule commentRule;
    commentFormat.setForeground(QColor(192, 192, 192, 255));//grey color for comment
    commentFormat.setFontItalic(true);
    commentRule.pattern = QRegularExpression("#[^\n]*");
    commentRule.format = commentFormat;
    highlightingRules.append(commentRule);
}

HighlightTextBox::~HighlightTextBox()
{
    
}

void HighlightTextBox::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    setCurrentBlockState(0);
}

void HighlightTextBox::setTextQueue(const QStringList& textQueue)
{
    highlightingRules.clear();
    HighlightingRule rule;

    const QString tmp("\\b");
    foreach(const QString& str,textQueue)
    {   
        QString pattern(tmp);
        pattern += str;
        pattern += tmp;
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
}
