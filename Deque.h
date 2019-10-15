#ifndef DEQUE_H_
#define DEQUE_H_

//this is just for test
//this is other people changing

#include<iostream>

template <typename T>
struct Node
{
    T Value;
    Node* pNode;

    Node(T value)
    {
        Value = value;
        pNode = nullptr;
    }
};

template <typename T>
struct DequeList
{
    Node<T>* pFrontList;
    Node<T>* pBackList;

    DequeList()
        : pFrontList(nullptr)
        , pBackList(nullptr)
    {
    }
};

template <typename T>
class Deque
{
public:
    Deque()
    : m_oDequeList()
    {
    };
    ~Deque(){};

public:
    void Push_Back(T value)
    {
        Node<T>* pTemp = new Node<T>(value);

        if (nullptr == m_oDequeList.pFrontList)
        {
            m_oDequeList.pFrontList = pTemp;
            return;
        }

        Node<T>* p = m_oDequeList.pFrontList;
        Node<T>** pCouldChangeTempNode = nullptr;
        while (p != nullptr)
        {
            pCouldChangeTempNode = &p->pNode;
            p = p->pNode;
        }

        *pCouldChangeTempNode = pTemp;
        m_oDequeList.pBackList = pTemp;
    }

    T Pop_Front()
    {
        try
        {
            T value{};
            if (m_oDequeList.pFrontList != nullptr)
            {
                value = m_oDequeList.pFrontList->Value;
                Node<T>* pTemp = m_oDequeList.pFrontList->pNode;
                delete m_oDequeList.pFrontList;
                m_oDequeList.pFrontList = pTemp;
            }
            else
            {
                throw value;
            }
            return value;
        }
        catch (...)
        {
            std::cout << "在 catch(…) block 中, 抛出的int类型的异常对象被处理" << std::endl;
        }
    }

    bool Empty()
    {
       return !Size();
    }

    int Size()
    {
      return SearchBy(m_oDequeList.pFrontList);
    }

    void Clear()
    {
        Node<T>* pTemp = m_oDequeList.pFrontList;
        Node<T>* pNextNode = m_oDequeList.pFrontList->pNode;

        while (pTemp != nullptr)
        {
            delete pTemp;
            pTemp = pNextNode;
            
            if (nullptr == pNextNode)
            {
                m_oDequeList.pFrontList = nullptr;
                break;
            }
            pNextNode = pNextNode->pNode;
        }
    }

    void Delete(T TValue)
    {
        Node<T>* pTemp = m_oDequeList.pFrontList;
        Node<T>* pTemp01 = nullptr;
        Node<T>** pTemp02 = &m_oDequeList.pFrontList;

        while (pTemp != nullptr)
        {
            if (pTemp->Value == TValue)
            {
                Node<T>* pTempNext = pTemp->pNode;

                if (pTemp == m_oDequeList.pFrontList)
                {
                    delete m_oDequeList.pFrontList;
                    m_oDequeList.pFrontList = pTempNext;
                    break;
                }
                
                delete pTemp;
                pTemp = nullptr;
                (*pTemp02)->pNode = pTempNext;
                break;
            }
            pTemp01 = pTemp;
            pTemp02 = &pTemp01;
            pTemp = pTemp->pNode;
        }

        return;
    }

private:
    int SearchBy(Node<T>* pNode)
    {
        if (pNode != nullptr)
        {
            return SearchBy(pNode->pNode) + 1;
        }
        return 0;
    }

private:
    DequeList<T> m_oDequeList;
};
#endif
